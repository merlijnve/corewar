/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 19:53:23 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/08/09 21:07:47 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add(t_cursor *cursor, char *mem)
{
	int		arg1;
	int		arg2;
	int		arg3;
	int		sum;

	arg1 = mem[(cursor->pos + 2) % MEM_SIZE];
	arg2 = mem[(cursor->pos + 3) % MEM_SIZE];
	arg3 = mem[(cursor->pos + 4) % MEM_SIZE];
	if (is_registry(arg1) && is_registry(arg2) && is_registry(arg3))
	{
		sum = cursor->registries[arg1] + cursor->registries[arg2];
		cursor->registries[arg3] = sum;
		if (sum == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
}
