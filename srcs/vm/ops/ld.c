/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ld.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 20:01:26 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/17 21:50:18 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_ld_argument_types(t_argument *args)
{
	if (args[0].type != ARG_TYPE_DIR && args[0].type != ARG_TYPE_IND)
		return (ERROR);
	if (args[1].type != ARG_TYPE_REG)
		return (ERROR);
	if (args[2].type != ARG_TYPE_NONE)
		return (ERROR);
	return (OK);
}

/*
**	Direct/indirect argument needs to skip 2 bytes (opcode + encoding)
**	Registry argument needs to skip 6 bytes (opcode + encoding + dir/ind of 4)
*/

static void	get_ld_argument_values(char *mem, t_cursor *cursor)
{
	int	offset;

	offset = 2;
	if (cursor->args[0].type == ARG_TYPE_DIR)
	{
		cursor->args[0].value = get_direct_argument(mem, 4, cursor->pos +
		offset);
		offset += 4;
	}
	else
	{
		cursor->args[0].value = get_indirect_argument(mem, cursor->pos, offset,
		true);
		offset += 2;
	}
	cursor->args[1].value = mem[get_pos(cursor->pos, offset)];
}

/*
**	LD
**	Loads value of 1st argument into register of 2nd argument
**	t_dir size of LD = 4
*/

void		ld(char *mem, t_cursor *cursor)
{
	get_argument_types(mem, cursor);
	if (check_ld_argument_types(cursor->args) == ERROR)
		return ;
	get_ld_argument_values(mem, cursor);
	if (is_registry(cursor->args[1].value))
	{
		cursor->registries[cursor->args[1].value - 1] = cursor->args[0].value;
		if (cursor->args[0].value == 0)
			cursor->carry = 1;
		else
			cursor->carry = 0;
	}
}
