/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sub.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 19:45:02 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/10 14:26:26 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		inst_sub(t_arena *arena, t_cursor *cursor)
{
	int args[2];
	int sum;

	if (arena == NULL || cursor == NULL)
		return; 
	args[0] = cursor->registries[cursor->args[0].value - 1];
	args[1] = cursor->registries[cursor->args[1].value - 1];
	sum = args[0] - args[1];
	cursor->registries[cursor->args[2].value - 1] = sum;
	if (sum == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
