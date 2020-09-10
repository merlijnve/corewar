/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 21:42:27 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/10 14:29:32 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	STI
**	idx
*/

void		inst_sti(t_arena *arena, t_cursor *cursor)
{
	if (arena == NULL || cursor == NULL)
		return;
	if (cursor->args[1].type == kTReg)
		cursor->args[1].value = cursor->registries[cursor->args[1].value - 1];
	if (cursor->args[2].type == kTReg)
		cursor->args[2].value = cursor->registries[cursor->args[2].value - 1];
	write_4_bytes(arena->mem,
		get_pos(cursor->pos,
			(cursor->args[1].value + cursor->args[2].value) % IDX_MOD),
		cursor->registries[cursor->args[0].value - 1]);
}
