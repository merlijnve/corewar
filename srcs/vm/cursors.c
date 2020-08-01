/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursors.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 17:08:19 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/08/01 18:50:44 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

t_cursor    *cursor_create()
{
    t_cursor *cursor;

    cursor = ft_memalloc(sizeof(t_cursor));
    if (cursor == NULL)
        return NULL;
    cursor->cycles_to_die = CYCLE_TO_DIE;
    return cursor;
}

t_cursor *cursor_add(t_cursor **acursor, t_cursor *new)
{
    if (acursor != NULL && new != NULL)
	{
		new->next = *acursor;
		*acursor = new;
	}
}

/*
** Initialize cursors at proper positions
**
*/

void    init_cursors(t_arena *arena_s)
{
    int i;
    t_cursor *start;
    t_cursor *current;

    i = 0;
    start = NULL;
    current = NULL;
    while (i < arena_s->champion_count)
    {
        if (arena_s->champions[i].id != -1)
        {
            current = cursor_create();
            current->id = arena_s->cursor_count;
            current->pos = arena_s->champions[i].mem_index;
            if (start == NULL)
                start = current;
            else
                cursor_add(&start, current);
            arena_s->cursor_count++;
        }
        ++i;
    }

    arena_s->cursors = start;
}