/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursors.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 17:08:19 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/10 13:58:24 by wmisiedj      ########   odam.nl         */
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
    arena->cells[get_pos(pos, 0)].taken = 1;
}

t_cursor    *cursor_add(t_arena *arena, t_cursor *clone)
{
    t_cursor *cursor;

    cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor));
    cursor->pos = -1;
    if (cursor == NULL)
        return (NULL);
    else
    {
        if (clone != NULL)
		{
			ft_memcpy(cursor, clone, sizeof(t_cursor));
            cursor_setpos(arena, cursor, clone->pos + get_pos(clone->args[0].value % IDX_MOD, 0));
		}
        cursor->next = arena->cursors;
        arena->cursor_count++;
		arena->cursors = cursor;
		cursor->id = arena->cursor_count;
    }
    return (arena->cursors);
}

void        cursor_del(t_cursor **head, int id)
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
