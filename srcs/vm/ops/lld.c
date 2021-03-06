/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lld.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 22:47:46 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/16 22:50:34 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	LLD
**	Loads value of 1st argument into register of 2nd argument
**	t_dir size of LLD = 4
*/

void		inst_lld(t_arena *arena, t_cursor *cursor)
{
	if (arena == NULL || cursor == NULL)
		return ;
	if (cursor->args[0].type == kTInd)
		cursor->args[0].value = read_2_bytes(arena->mem,
		cursor->pos + cursor->args[0].value);
	cursor->registries[cursor->args[1].value - 1] = cursor->args[0].value;
	if (cursor->args[0].value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
