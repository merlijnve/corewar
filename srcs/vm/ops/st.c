/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   st.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 20:13:20 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/07 12:00:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	ST
**	Argument 1: registry to take value from
**	Argument 2: registry or address to write value to
*/

void		inst_st(t_arena *arena, t_cursor *cursor)
{
	if (cursor->args[1].type == kTReg)
		cursor->registries[cursor->args[1].value] = cursor->registries[cursor->args[0].value - 1];
	else
	{
		// TODO: Check if adress is correct
		write_4_bytes(&arena->mem[0], get_pos(cursor->pos, cursor->args[1].value), cursor->registries[cursor->args[0].value - 1]);
	}
}
