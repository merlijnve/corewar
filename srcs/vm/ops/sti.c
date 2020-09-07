/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sti.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/18 21:42:27 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/19 18:22:29 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	check_sti_argument_types(t_argument *args)
{
	if (args[0].type != ARG_TYPE_REG)
		return (kError);
	if (args[1].type != ARG_TYPE_DIR && args[1].type != ARG_TYPE_IND &&
	args[1].type != ARG_TYPE_REG)
		return (kError);
	if (args[2].type != ARG_TYPE_REG && args[2].type != ARG_TYPE_DIR)
		return (kError);
	return (kOk);
}

static int	get_second_sti_argument(char *mem, t_cursor *cursor)
{
	int offset;

	offset = 3;
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
	if (cursor->args[1].type == ARG_TYPE_IND)
	{
		cursor->args[1].value = get_indirect_argument(mem, cursor->pos, offset,
		true);
		offset += 2;
	}
	return (offset);
}

static int	get_third_sti_argument(char *mem, t_cursor *cursor, int offset)
{
	if (cursor->args[2].type == ARG_TYPE_REG)
	{
		cursor->args[2].value = mem[get_pos(cursor->pos, offset)];
		if (!is_registry(cursor->args[2].value))
			return (kError);
		cursor->args[2].value = cursor->registries[cursor->args[2].value - 1];
		offset += 1;
	}
	if (cursor->args[2].type == ARG_TYPE_DIR)
	{
		cursor->args[2].value = get_direct_argument(mem, 2, cursor->pos +
		offset);
		offset += 2;
	}
	return (offset);
}

int			get_sti_argument_values(char *mem, t_cursor *cursor)
{
	int offset;

	cursor->args[0].value = mem[get_pos(cursor->pos, 2)];
	if (!is_registry(cursor->args[0].value))
		return (kError);
	offset = get_second_sti_argument(mem, cursor);
	if (offset == kError)
		return (kError);
	offset = get_third_sti_argument(mem, cursor, offset);
	if (offset == kError)
		return (kError);
	return (kOk);
}

/*
**	STI
**	idx
*/

void		inst_sti(t_arena *arena, t_cursor *cursor)
{
	int	write_pos;

	get_argument_types(arena->mem, cursor);
	if (check_sti_argument_types(cursor->args) == kError)
		return ;
	if (get_sti_argument_values(arena->mem, cursor))
		return ;
	write_pos = cursor->pos + (cursor->args[1].value + cursor->args[2].value) %
	IDX_MOD;
	write_4_bytes((unsigned char *)arena->mem, write_pos,
	cursor->registries[cursor->args[0].value - 1]);
}
