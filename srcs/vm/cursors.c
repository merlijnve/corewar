/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursors.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 17:08:19 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/03 20:27:43 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

void        cursor_setpos(t_arena *arena, t_cursor *cursor, int pos)
{
    if (cursor->pos != -1) {
        arena->cells[get_pos(cursor->pos, 0)].taken = 0;
    }
    cursor->pos = get_pos(pos, 0);
    arena->cells[get_pos(cursor->pos, 0)].taken = 1;
}

// TODO: Should place cursor in the beginning of the list
t_cursor *cursor_add(t_arena *arena, t_cursor *clone)
{
    t_cursor *cursor;

    cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor));

    cursor->pos = -1;

    if (cursor == NULL)
    {
        ;// ERROR MEMORY
    }
    else
    {
        if (clone != NULL)
            ft_memcpy(cursor, clone, sizeof(t_cursor));
        cursor->id = arena->cursor_count;
        cursor->next = NULL;
        arena->cursor_count++;
        if (arena->cursors == NULL)
            arena->cursors = cursor;
        else
        {
            cursor->next = arena->cursors;
            arena->cursors = cursor;
        }
    }
    return (arena->cursors);
}

void    cursor_del(t_cursor **head, int id)
{
	t_cursor *temp;
	t_cursor *prev;
	t_cursor *found;

	temp = *head;
	prev = NULL;
	found = NULL;
	while (temp != NULL)
	{
		if (temp->id == id)
		{
			found = temp;
			break ;
		}
		prev = temp;
		temp = temp->next;
	}
	if (*head == found && found != NULL)
		*head = found->next;
	else if (prev != NULL && found != NULL)
		prev->next = found->next;
	free(found);
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
			// TODO: NULL check?
            current = cursor_add(arena_s, NULL);
            cursor_setpos(arena_s, current, arena_s->champions[i].mem_index);
			current->timeout = -1;
			current->registries[0] = - arena_s->champions[i].id;
        }
        ++i;
    }
}
