/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lldi.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 22:54:16 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/07 12:00:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	GET_LDI_ARGUMENT_VALUES
**	gets all arguments corresponding to their types
**	returns ERROR if is_registry returns false
**	offset starts at 2 (opcode + encoding byte)
**	t_dir_size = 2
*/

static int	get_first_lldi_argument(char *mem, t_cursor *cursor)
{
	int offset;

	offset = 2;
	if (cursor->args[0].type == ARG_TYPE_REG)
	{
		cursor->args[0].value = mem[get_pos(cursor->pos, offset)];
		if (!is_registry(cursor->args[0].value))
			return (kError);
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

static int	get_second_lldi_argument(char *mem, t_cursor *cursor, int offset)
{
	if (cursor->args[1].type == ARG_TYPE_REG)
	{
		cursor->args[1].value = mem[get_pos(cursor->pos, offset)];
		if (!is_registry(cursor->args[1].value))
			return (kError);
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

static int	get_lldi_argument_values(char *mem, t_cursor *cursor)
{
	int offset;

	offset = get_first_lldi_argument(mem, cursor);
	if (offset == kError)
		return (kError);
	offset = get_second_lldi_argument(mem, cursor, offset);
	if (offset == kError)
		return (kError);
	cursor->args[2].value = mem[get_pos(cursor->pos, offset)];
	if (!is_registry(cursor->args[2].value))
		return (kError);
	return (kOk);
}

/*
**	LLDI
**	Loads value from address calculated with argument 1 and 2 into
**	registry given in argument 3
**	Uses no modulo in the value calculation, like operation ldi
*/

void		inst_lldi(t_arena *arena, t_cursor *cursor)
{
	int value;

	value = read_4_bytes(arena->mem, cursor->pos + cursor->args[0].value +
	cursor->args[1].value);
	cursor->registries[cursor->args[2].value - 1] = value;
}
