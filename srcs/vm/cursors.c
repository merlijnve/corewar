/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursors.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 17:08:19 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/08/18 13:17:42 by wmisiedj      ########   odam.nl         */
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
    return cursor;
}

t_cursor    *cursor_clone(t_cursor *origin)
{
    t_cursor *cursor;

    if (origin == NULL)
        return (NULL);
    cursor = ft_memalloc(sizeof(t_cursor));
    if (cursor == NULL)
        return (NULL);
    ft_memcpy(cursor, origin, sizeof(t_cursor));
    
    // TODO: Assign new ID / position / position in list for cursor?
    return (cursor);
}

t_cursor *cursor_add(t_cursor **acursor, t_cursor *new)
{
    if (acursor != NULL && new != NULL)
	{
		new->next = *acursor;
		*acursor = new;
	}

    return (*acursor);
}

t_cursor *cursor_del(t_cursor **acursor, t_cursor *del)
{
    debug_printf("[Cursor] Deleting cursor %d", del->id);

    // TODO: Actually delete the specific cursor.
    return (*acursor);
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