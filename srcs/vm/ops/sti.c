/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 21:42:27 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/07 12:00:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	STI
**	idx
*/

void		inst_sti(t_arena *arena, t_cursor *cursor)
{
	int	write_pos;

	write_pos = cursor->pos + (cursor->args[1].value + cursor->args[2].value) %
	IDX_MOD;
	write_4_bytes((unsigned char *)arena->mem, write_pos,
	cursor->registries[cursor->args[0].value - 1]);
}
