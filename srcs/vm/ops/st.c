/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   st.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 20:13:20 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/19 18:22:06 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_st_argument_types(t_argument *args)
{
	if (args[0].type != ARG_TYPE_REG)
		return (ERROR);
	if (args[1].type != ARG_TYPE_REG && args[1].type != ARG_TYPE_IND)
		return (ERROR);
	if (args[2].type != ARG_TYPE_NONE)
		return (ERROR);
	return (OK);
}

/*
**	ST
**	Argument 1: registry to take value from
**	Argument 2: registry or address to write value to
*/

void		st(char *mem, t_cursor *cursor)
{
	int	arg1;
	int	arg2;

	get_argument_types(mem, cursor);
	if (check_st_argument_types(cursor->args) == ERROR)
		return ;
	arg1 = mem[get_pos(cursor->pos, 2)];
	if (!is_registry(arg1))
		return ;
	if (cursor->args[1].type == ARG_TYPE_REG)
	{
		arg2 = mem[get_pos(cursor->pos, 3)];
		if (is_registry(arg2))
			cursor->registries[arg2 - 1] = cursor->registries[arg1 - 1];
	}
	else
	{
		arg2 = mem[get_pos(cursor->pos, 3)] << 8;
		arg2 += mem[get_pos(cursor->pos, 4)];
		write_4_bytes((unsigned char *)mem, cursor->pos + (arg2 % IDX_MOD),
		cursor->registries[arg1 - 1]);
	}
}
