/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   and.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 15:51:14 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/19 18:20:07 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_and_argument_types(t_argument *args)
{
	if (args[0].type != ARG_TYPE_REG && args[0].type != ARG_TYPE_DIR &&
	args[0].type != ARG_TYPE_IND)
		return (kError);
	if (args[1].type != ARG_TYPE_REG && args[1].type != ARG_TYPE_DIR &&
	args[1].type != ARG_TYPE_IND)
		return (kError);
	if (args[2].type != ARG_TYPE_REG)
		return (kError);
	return (kOk);
}

static int	get_argument_all_types(char *mem, t_cursor *cursor, int offset,
int i)
{
	if (cursor->args[i].type == ARG_TYPE_REG)
	{
		cursor->args[i].value = mem[get_pos(cursor->pos, offset)];
		if (!is_registry(cursor->args[i].value))
			return (kError);
		cursor->args[i].value = cursor->registries[cursor->args[i].value - 1];
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

static int	get_and_argument_values(char *mem, t_cursor *cursor)
{
	int offset;

	offset = 2;
	offset = get_argument_all_types(mem, cursor, offset, 0);
	if (offset == kError)
		return (kError);
	offset = get_argument_all_types(mem, cursor, offset, 1);
	if (offset == kError)
		return (kError);
	cursor->args[2].value = mem[get_pos(cursor->pos, offset)];
	if (!is_registry(cursor->args[2].value))
		return (kError);
	return (kOk);
}

/*
**	AND
**	Performs bitwise AND on argument 1 and 2
**	Saves result in registry from argument 3
*/

void		inst_and(t_arena *arena, t_cursor *cursor)
{
	int	result;

	get_argument_types(arena->mem, cursor);
	if (check_and_argument_types(cursor->args) == kError)
		return ;
	if (get_and_argument_values(arena->mem, cursor) == kError)
		return ;
	result = cursor->args[0].value & cursor->args[1].value;
	cursor->registries[cursor->args[2].value - 1] = result;
	if (result == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
