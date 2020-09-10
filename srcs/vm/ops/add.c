/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 19:53:23 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/10 14:27:01 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		inst_add(t_arena *arena, t_cursor *cursor)
{
	int args[2];
	int sum;

	if (arena == NULL || cursor == NULL)
		return; 
	args[0] = cursor->registries[cursor->args[0].value - 1];
	args[1] = cursor->registries[cursor->args[1].value - 1];
	sum = args[0] + args[1];
	cursor->registries[cursor->args[2].value - 1] = sum;
	if (sum == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
