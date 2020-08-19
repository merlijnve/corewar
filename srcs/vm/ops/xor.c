/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   xor.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 17:52:43 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/19 17:53:27 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   or.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 17:49:22 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/19 17:52:52 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
static int	check_xor_argument_types(t_argument *args)
{
	if (args[0].type != ARG_TYPE_REG && args[0].type != ARG_TYPE_DIR &&
	args[0].type != ARG_TYPE_IND)
		return (ERROR);
	if (args[1].type != ARG_TYPE_REG && args[1].type != ARG_TYPE_DIR &&
	args[1].type != ARG_TYPE_IND)
		return (ERROR);
	if (args[2].type != ARG_TYPE_REG)
		return (ERROR);
	return (OK);
}

static int	get_argument_all_types(char *mem, t_cursor *cursor, int offset,
int i)
{
	if (cursor->args[i].type == ARG_TYPE_REG)
	{
		cursor->args[i].value = mem[get_pos(cursor->pos, offset)];
		if (!is_registry(cursor->args[i].value))
			return (ERROR);
		cursor->args[i].value = cursor->registries[cursor->args[i].value];
		offset += 1;
	}
	if (cursor->args[i].type == ARG_TYPE_DIR)
	{
		cursor->args[i].value = get_direct_argument(mem, 2, cursor->pos +
		offset);
		offset += 4;
	}
	if (cursor->args[i].type == ARG_TYPE_IND)
	{
		cursor->args[i].value = get_indirect_argument(mem, cursor->pos, offset,
		true);
		offset += 2;
	}
	return (offset);
}

static int	get_xor_argument_values(char *mem, t_cursor *cursor)
{
	int offset;

	offset = 2;
	offset = get_argument_all_types(mem, cursor, offset, 0);
	if (offset == ERROR)
		return (ERROR);
	offset = get_argument_all_types(mem, cursor, offset, 1);
	if (offset == ERROR)
		return (ERROR);
	cursor->args[2].value = mem[get_pos(cursor->pos, offset)];
	if (!is_registry(cursor->args[2].value))
		return (ERROR);
	return (OK);
}

/*
**	XOR
**	Performs bitwise XOR on argument 1 and 2
**	Saves result in registry from argument 3
*/

void		xor(char *mem, t_cursor *cursor)
{
	int	result;

	get_argument_types(mem, cursor);
	if (check_xor_argument_types(cursor->args) == ERROR)
		return ;
	if (get_xor_argument_values(mem, cursor) == ERROR)
		return ;
	result = cursor->args[0].value ^ cursor->args[1].value;
	cursor->registries[cursor->args[2].value] = result;
	if (result == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
