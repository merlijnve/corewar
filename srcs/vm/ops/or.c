/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   or.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 17:49:22 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/10 14:26:54 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	OR
**	Performs bitwise OR on argument 1 and 2
**	Saves result in registry from argument 3
*/

void		inst_or(t_arena *arena, t_cursor *cursor)
{
	int	result;

	if (arena == NULL || cursor == NULL)
		return; 
	if (cursor->args[0].type == kTReg)
		cursor->args[0].value = cursor->registries[cursor->args[0].value - 1];
	if (cursor->args[1].type == kTReg)
		cursor->args[1].value = cursor->registries[cursor->args[1].value - 1];
	result = cursor->args[0].value | cursor->args[1].value;
	cursor->registries[cursor->args[2].value - 1] = result;
	if (result == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
