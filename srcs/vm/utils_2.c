/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 20:48:30 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/03 20:35:39 by wmisiedj      ########   odam.nl         */
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

int		args_lenght(t_enbyte byte, t_inst inst)
{
	int len;

	len = 0;
	if (is_opcode(inst))
	{
		len += arg_length(get_arg(byte, inst, 1), inst);
		len += arg_length(get_arg(byte, inst, 2), inst);
		len += arg_length(get_arg(byte, inst, 3), inst);
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

t_enbyte *get_enbyte(t_arena *arena, t_index pos)
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

int		get_pos(int cursor_pos, int offset)
{
	return ((cursor_pos + offset) % MEM_SIZE);
}

/*
**	READ_4_BYTES
**	Reads 4 bytes of memory, using get_pos to keep reading within memory field
*/

int		read_4_bytes(char *mem, int pos)
{
	int	sum;

	sum = mem[get_pos(pos, 0)] << 24;
	sum += mem[get_pos(pos, 1)] << 16;
	sum += mem[get_pos(pos, 2)] << 8;
	sum += mem[get_pos(pos, 3)];
	return (sum);
}

void	write_4_bytes(unsigned char *mem, int pos, int value)
{
	int temp;

	temp = value >> 24 & 0xff;
	mem[get_pos(pos, 0)] = temp;
	temp = value >> 16 & 0xff;
	mem[get_pos(pos, 1)] = temp;
	temp = value >> 8 & 0xff;
	mem[get_pos(pos, 2)] = temp;
	temp = value & 0xff;
	mem[get_pos(pos, 3)] = temp;
}

int		read_2_bytes(char *mem, int pos)
{
	int	sum;
	sum = mem[get_pos(pos, 0)] << 8;
	sum += mem[get_pos(pos, 1)];
	return (sum);
}

void	write_2_bytes(unsigned char *mem, int pos, int value)
{
	int temp;

	temp = value >> 8 & 0xff;
	mem[get_pos(pos, 0)] = temp;
	temp = value & 0xff;
	mem[get_pos(pos, 1)] = temp;
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
