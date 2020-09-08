/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ldi.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 20:58:31 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/07 12:00:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	LDI
**	Loads value from address calculated with argument 1 and 2 into
**	registry given in argument 3
*/

void		inst_ldi(t_arena *arena, t_cursor *cursor)
{
	int value;

	if (cursor->args[0].type == kTReg)
		cursor->args[0].value = cursor->registries[cursor->args[0].value - 1];
	if (cursor->args[1].type == kTReg)
		cursor->args[1].value = cursor->registries[cursor->args[1].value - 1];
	value = read_4_bytes(arena->mem,
		get_pos(cursor->pos, (cursor->args[0].value + cursor->args[1].value) % IDX_MOD));
	cursor->registries[cursor->args[2].value - 1] = value;
}
