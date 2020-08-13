/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 19:53:23 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/08/13 15:29:39 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_add_argument_types(t_argument *args)
{
	if (args[0].type != ARG_TYPE_REG
	|| args[1].type != ARG_TYPE_REG
	|| args[2].type != ARG_TYPE_REG)
		return (ERROR);
	return (OK);
}

void		add(char *mem, t_cursor *cursor)
{
	int		arg1;
	int		arg2;
	int		arg3;
	int		sum;

	get_argument_types(mem, cursor);
	if (check_add_argument_types(cursor->args) == ERROR)
		return ;
	arg1 = mem[(cursor->pos + 2) % MEM_SIZE];
	arg2 = mem[(cursor->pos + 3) % MEM_SIZE];
	arg3 = mem[(cursor->pos + 4) % MEM_SIZE];
	if (is_registry(arg1) && is_registry(arg2) && is_registry(arg3))
	{
		sum = cursor->registries[arg1 - 1] + cursor->registries[arg2 - 1];
		cursor->registries[arg3 - 1] = sum;
		if (sum == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
}
