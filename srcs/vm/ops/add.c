/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 19:53:23 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/08/12 16:29:29 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	check_add_argument_types(t_argument *args)
{
	if (args[0].type != ARG_TYPE_REG
	|| args[1].type != ARG_TYPE_REG
	|| args[2].type != ARG_TYPE_REG)
		vm_error(ERR_BAD_ARGTYPE);
}

void		add(char *mem, t_cursor *cursor)
{
	int		arg1;
	int		arg2;
	int		arg3;
	int		sum;

	get_arguments(mem, cursor);
	check_add_argument_types(cursor->args);
	arg1 = mem[(cursor->pos + 2) % MEM_SIZE];
	arg2 = mem[(cursor->pos + 3) % MEM_SIZE];
	arg3 = mem[(cursor->pos + 4) % MEM_SIZE];
	if (is_registry(arg1) == OK && is_registry(arg2) == OK && is_registry(arg3))
	{
		sum = cursor->registries[arg1] + cursor->registries[arg2];
		cursor->registries[arg3] = sum;
		if (sum == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
}
