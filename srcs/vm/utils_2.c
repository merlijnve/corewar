/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 20:48:30 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/11 22:07:59 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_args_type get_arg(t_enbyte byte, t_inst inst, int argnr)
{
	if (get_opinfo(inst)->has_enbyte)
	{
		if (argnr == 1)
			return (byte.arg1);
		if (argnr == 2)
			return (byte.arg2);
		if (argnr == 3)
			return (byte.arg3);
	}
	return (get_opinfo(inst)->v_args[argnr - 1].arg1);
}

int		arg_length(t_args_type type, t_inst inst)
{
	if (type == kTReg)
		return (REG_SIZE_ASM);
	else if (type == kTDir)
		return (get_opinfo(inst)->dir_size);
	else if (type == kTInd)
		return (IND_SIZE_ASM);
	else if (type == kTNone)
		return (0);
	return (0);
}

int		args_length(t_enbyte byte, t_inst inst)
{
	int len;

	len = 1;
	if (is_opcode(inst))
	{
		len += arg_length(get_arg(byte, inst, 1), inst);
		len += arg_length(get_arg(byte, inst, 2), inst);
		len += arg_length(get_arg(byte, inst, 3), inst);
		len += get_opinfo(inst)->has_enbyte ? 1 : 0;
	}
	return (len);
}

void	reverse_eb(t_enbyte *eb)
{
	t_enbyte bc;

	bc = *eb;
	eb->arg1 = bc.arg4;
	eb->arg2 = bc.arg3;
	eb->arg3 = bc.arg2;
	eb->arg4 = bc.arg1;
}

t_enbyte *get_enbyte(t_arena *arena, long pos)
{
	t_enbyte *eb;
	eb = (t_enbyte *)&arena->mem[get_pos(pos, 1)];
	return (eb);
}

bool	is_opcode(t_inst inst)
{
	if (inst >= kInstLive && inst <= kInstAff)
		return (true);
	else
		return (false);
}

/*
**	GET_TIMEOUT
**	Get timeout per instruction
*/

int			get_timeout(t_inst inst)
{
	if (is_opcode(inst))
		return (get_opinfo(inst)->timeout);
	else
		// TODO: find out what should be placed here?
		// 0 so it will be moved in this cycle
		// to next byte and get -1 cycle to wait
		return (0);
}


/*
**	GET_POS
**	Gets new position in arena with modulo calculation
*/

long		get_pos(long cursor_pos, long offset)
{
	return (ft_mod((cursor_pos + offset), MEM_SIZE));
}

/*
**	READ_4_BYTES
**	Reads 4 bytes of memory, using get_pos to keep reading within memory field
*/

int		read_4_bytes(uint8_t *mem, long pos)
{
	uint32_t	sum;
	uint32_t	parts[4];

	parts[0] = mem[get_pos(pos, 0)];
	parts[1] = mem[get_pos(pos, 1)];
	parts[2] = mem[get_pos(pos, 2)];
	parts[3] = mem[get_pos(pos, 3)];
	sum =  parts[0] << 24;
	sum += parts[1] << 16;
	sum += parts[2] << 8;
	sum += parts[3];
	return (sum);
}

void	write_4_bytes(uint8_t *mem, long pos, int value)
{
	uint32_t parts[4];

	parts[0] = ((0xFFL << 24) & value) >> 24;
	parts[1] = ((0xFFL << 16) & value) >> 16;
	parts[2] = ((0xFFL <<  8) & value) >>  8;
	parts[3] = ((0xFFL <<  0) & value) >>  0;

	mem[get_pos(pos, 0)] =  parts[0];
	mem[get_pos(pos, 1)] =  parts[1];
	mem[get_pos(pos, 2)] =  parts[2];
	mem[get_pos(pos, 3)] =  parts[3];
}

int		read_2_bytes(uint8_t *mem, long pos)
{
	uint32_t	sum;
	uint32_t		parts[2];

	parts[0] = mem[get_pos(pos, 0)];
	parts[1] = mem[get_pos(pos, 1)];
	sum = parts[0] << 8;
	sum += parts[1];
	return (sum);
}

void	write_2_bytes(uint8_t *mem, long pos, int value)
{
	uint32_t parts[2];

	parts[0] = ((0xFFL <<  8) & value) >>  8;
	parts[1] = ((0xFFL <<  0) & value) >>  0;

	mem[get_pos(pos, 0)] =  parts[0];
	mem[get_pos(pos, 1)] =  parts[1];
}

/*
**	IS_REGISTRY
**	Checks if given argument is a valid registry
*/

int		is_registry(int arg)
{
	if (arg > 0 && arg <= REG_NUMBER)
		return (true);
	return (false);
}

void		set_champ_zero(t_arena *arena, int i)
{
	arena->champions[i].id = 0;
	arena->champions[i].fd = 0;
	arena->champions[i].argv_index = 0;
	arena->champions[i].file_name = NULL;
}

void		set_champ_name(t_arena *arena, char **argv)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (arena->champions[i].argv_index > 0)
			arena->champions[i].file_name = argv[arena->champions[i].argv_index];
		i++;
	}
}
