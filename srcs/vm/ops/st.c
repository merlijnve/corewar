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
		return (kError);
	if (args[1].type != ARG_TYPE_REG && args[1].type != ARG_TYPE_IND)
		return (kError);
	if (args[2].type != ARG_TYPE_NONE)
		return (kError);
	return (kOk);
}

/*
**	ST
**	Argument 1: registry to take value from
**	Argument 2: registry or address to write value to
*/

void		inst_st(t_arena *arena, t_cursor *cursor)
{
	int	arg1;
	int	arg2;

	get_argument_types(arena->mem, cursor);
	if (check_st_argument_types(cursor->args) == kError)
		return ;
	arg1 = arena->mem[get_pos(cursor->pos, 2)];
	if (!is_registry(arg1))
		return ;
	if (cursor->args[1].type == ARG_TYPE_REG)
	{
		arg2 = arena->mem[get_pos(cursor->pos, 3)];
		if (is_registry(arg2))
			cursor->registries[arg2 - 1] = cursor->registries[arg1 - 1];
	}
	else
	{
		arg2 = arena->mem[get_pos(cursor->pos, 3)] << 8;
		arg2 += arena->mem[get_pos(cursor->pos, 4)];
		write_4_bytes((unsigned char *)arena->mem, cursor->pos + (arg2 % IDX_MOD),
		cursor->registries[arg1 - 1]);
	}
}
