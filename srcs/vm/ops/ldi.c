/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ldi.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 20:58:31 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/19 18:20:55 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_ldi_argument_types(t_argument *args)
{
	if (args[0].type != ARG_TYPE_DIR && args[0].type != ARG_TYPE_IND &&
	args[0].type != ARG_TYPE_REG)
		return (ERROR);
	if (args[1].type != ARG_TYPE_REG && args[1].type != ARG_TYPE_DIR)
		return (ERROR);
	if (args[2].type != ARG_TYPE_REG)
		return (ERROR);
	return (OK);
}

/*
**	GET_LDI_ARGUMENT_VALUES
**	gets all arguments corresponding to their types
**	returns ERROR if is_registry returns false
**	offset starts at 2 (opcode + encoding byte)
**	t_dir_size = 2
*/

static int	get_first_ldi_argument(char *mem, t_cursor *cursor)
{
	int offset;

	offset = 2;
	if (cursor->args[0].type == ARG_TYPE_REG)
	{
		cursor->args[0].value = mem[get_pos(cursor->pos, offset)];
		if (!is_registry(cursor->args[0].value))
			return (ERROR);
		cursor->args[0].value = cursor->registries[cursor->args[0].value - 1];
		offset += 1;
	}
	if (cursor->args[0].type == ARG_TYPE_DIR)
	{
		cursor->args[0].value = get_direct_argument(mem, 2, cursor->pos +
		offset);
		offset += 2;
	}
	if (cursor->args[0].type == ARG_TYPE_IND)
	{
		cursor->args[0].value = get_indirect_argument(mem, cursor->pos, offset,
		true);
		offset += 2;
	}
	return (offset);
}

static int	get_second_ldi_argument(char *mem, t_cursor *cursor, int offset)
{
	if (cursor->args[1].type == ARG_TYPE_REG)
	{
		cursor->args[1].value = mem[get_pos(cursor->pos, offset)];
		if (!is_registry(cursor->args[1].value))
			return (ERROR);
		cursor->args[1].value = cursor->registries[cursor->args[1].value - 1];
		offset += 1;
	}
	if (cursor->args[1].type == ARG_TYPE_DIR)
	{
		cursor->args[1].value = get_direct_argument(mem, 2, cursor->pos +
		offset);
		offset += 2;
	}
	return (offset);
}

static int	get_ldi_argument_values(char *mem, t_cursor *cursor)
{
	int offset;

	offset = get_first_ldi_argument(mem, cursor);
	if (offset == ERROR)
		return (ERROR);
	offset = get_second_ldi_argument(mem, cursor, offset);
	if (offset == ERROR)
		return (ERROR);
	cursor->args[2].value = mem[get_pos(cursor->pos, offset)];
	if (!is_registry(cursor->args[2].value))
		return (ERROR);
	return (OK);
}

/*
**	LDI
**	Loads value from address calculated with argument 1 and 2 into
**	registry given in argument 3
*/

void		ldi(char *mem, t_cursor *cursor)
{
	int value;

	get_argument_types(mem, cursor);
	if (check_ldi_argument_types(cursor->args) == ERROR)
		return ;
	if (get_ldi_argument_values(mem, cursor) == ERROR)
		return ;
	value = read_4_bytes(mem, cursor->pos + ((cursor->args[0].value +
	cursor->args[1].value) % IDX_MOD));
	cursor->registries[cursor->args[2].value - 1] = value;
}
