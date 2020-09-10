/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursors.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/01 17:08:19 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/10 22:28:41 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "libft.h"

int			cursor_get_pid(t_cursor *cursor)
{
	if (cursor == NULL)
		return (0);
	if (cursor->registries[0] < 0 && cursor->registries[0] >= (-MAX_PLAYERS))
		return ((cursor->registries[0] * (-1)));
	return (0);
}

void        cursor_setpos(t_arena *arena, t_cursor *cursor, int pos)
{
    if (cursor->pos != -1) {
        arena->cells[get_pos(cursor->pos, 0)].cursor = NULL;
    }
    cursor->pos = get_pos(pos, 0);
    arena->cells[get_pos(pos, 0)].cursor = cursor;
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
			ft_memcpy(cursor, clone, sizeof(t_cursor));
        cursor->next = arena->cursors;
        arena->cursor_count++;
		arena->cursors_active++;
		arena->cursors = cursor;
		cursor->id = arena->cursor_count;
    }
    return (arena->cursors);
}

void        cursor_del(t_arena *arena, int id)
{
	t_cursor *temp;
	t_cursor *prev;
	t_cursor *found;

	temp = arena->cursors;
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
	if (found == NULL)
		return;
	if (arena->cursors == found && found != NULL)
		arena->cursors = found->next;
	else if (prev != NULL && found != NULL)
		prev->next = found->next;
	free(found);
	arena->cursors_active--;
}
