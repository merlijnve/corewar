/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lfork.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 10:00:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 15:54:02 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	inst_lfork(t_arena *arena, t_cursor *cursor)
{
	t_cursor *fork;

	if (arena == NULL || cursor == NULL)
		return; 
	fork = cursor_add(arena, cursor);
    cursor_setpos(arena, fork, fork->pos + get_pos(fork->args[0].value, 0));
	fork->timeout = -1;
}
