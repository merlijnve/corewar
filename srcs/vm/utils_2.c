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

int		args_lenght(t_enbyte *byte, t_inst inst)
{
	int len;

	len = 0;
	if (is_opcode(inst))
	{
		if (get_opinfo(inst)->has_enbyte)
		{
			len += arg_length(byte->arg1, inst);
			len += arg_length(byte->arg2, inst);
			len += arg_length(byte->arg3, inst);
		}
		else
		{
			len += arg_length(get_opinfo(inst)->v_args[0].arg1, inst);
			len += arg_length(get_opinfo(inst)->v_args[1].arg1, inst);
			len += arg_length(get_opinfo(inst)->v_args[2].arg1, inst);
		}
	}
	return (len);
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
