//
//  args_loader.c
//  cw-vm
//
//  Created by Floris Fredrikze on 06/09/2020.
//

#include "vm.h"

int		ind_arg(char *mem, int idx)
{
	int value;

	value = read_4_bytes(mem, idx);
	return (value);
}

int		dir_arg(char *mem, int idx, int t_dir_size)
{
	int value;

	value = 0;
	if (t_dir_size == 2)
		value = read_2_bytes(mem, idx);
	else if (t_dir_size == 4)
		value = read_4_bytes(mem, idx);
	return (value);
}

int		reg_arg(char *mem, int idx, t_cursor *cursor, t_error ret)
{
	int reg;

	reg = mem[get_pos(idx, 0)];
	if (is_registry(reg))
	{
		ret = kOk;
		return (cursor->registries[reg]);
	}
	reg = kError;
	return (ret);
}

static bool	arg_for_idx(t_arena *arena, t_cursor *cur, int *offset, int nr)
{
	t_error		ret;
	int			arg_len;
	t_args_type	type;

	type = get_arg(get_enbyte(arena, cur->pos), cur->opcode, nr);
	ret = true;
	if (type != kTNone)
	{
		cur->args[nr - 1].type = type;
		arg_len = arg_length(type, cur->opcode);
		if (type == kTDir)
			cur->args[nr - 1].value = ind_arg(arena->mem, cur->pos + *offset);
		if (type == kTInd)
			cur->args[nr - 1].value = dir_arg(arena->mem, cur->pos + *offset, get_opinfo(cur->opcode)->dir_size);
		if (type == kTReg)
			cur->args[nr - 1].value = reg_arg(arena->mem, *offset, cur, ret);
		offset += arg_len;
	}
	return (ret);
}

bool	preload_args(t_arena *arena_s, t_cursor *cursor)
{
	bool		ret;
	int			offset;

	offset = 0;
	ret = arg_for_idx(arena_s, cursor, &offset, 1);
	if (ret)
		ret = arg_for_idx(arena_s, cursor, &offset, 2);
	if (ret)
		ret = arg_for_idx(arena_s, cursor, &offset, 3);
	return (ret);
}
