/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_arguments.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 14:41:11 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/20 16:38:04 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	GET_INDIRECT_ARGUMENT
**	Uses idx argument to check for IDX_MOD truncating
**	reads 4 bytes from address
**	returns int
*/

int		get_indirect_argument(char *mem, int cursor_pos, int arg_pos, bool idx)
{
	int arg_value;
	int	result;

	arg_pos += cursor_pos;
	arg_value = (int)mem[arg_pos] << 8;
	arg_value += mem[arg_pos + 1];
	if (idx == true)
		result = read_4_bytes(mem, cursor_pos + (arg_value % IDX_MOD));
	else
		result = read_4_bytes(mem, cursor_pos + arg_value);
	return (result);
}

/*
**	GET_DIRECT_ARGUMENT
**	Reverses 2 or 4 bytes into an int
**	pos should be position of argument to get (cursor->pos + offset)
**	t_dir_size should be 2 or 4
*/

int		get_direct_argument(char *mem, int t_dir_size, int arg_pos)
{
	int	sum;

	sum = 0;
	if (t_dir_size == 2)
	{
		sum = mem[get_pos(arg_pos, 0)] << 8;
		sum += mem[get_pos(arg_pos, 1)];
	}
	else if (t_dir_size == 4)
		sum = read_4_bytes(mem, arg_pos);
	return (sum);
}

int		calc_jump(t_cursor *cursor, int op)
{
	int	jump;
	int	i;

	i = 0;
	jump = 1;
	if (op != 15 || op != 12 ||
	op != 9 || op != 1)
		jump++;
	while (i < 3)
	{
		if (cursor->args[i].type == 3 || (op == 9 || op == 10
		|| op == 11 || op == 12 || op == 14 || op == 15))
			jump++;
		else if (cursor->args[i].type == 2 && (op != 9 || op != 10
		|| op != 11 || op != 12 || op != 14 || op != 15))
			jump = jump + 4;
		else if (cursor->args[i].type == 1)
			jump++;
		i++;
	}
	cursor->jump = jump;	
}

/*
**	GET_ARGUMENT_TYPES
**	Uses bitwise operators to split the encoding byte
**	into all three types
**	T_REG = 0x01 = 1
**	T_DIR = 0x10 = 2
**	T_IND = 0x11 = 3
**	empty = 0x00 = 0
*/

void	get_argument_types(char *mem, t_cursor *cursor)
{
	int	i;
	int byte;

	byte = mem[get_pos(cursor->pos, 1)];
	i = 2;
	if ((byte & 3) != 0)
		return ;
	while (i >= 0)
	{
		byte = byte >> 2;
		cursor->args[i].type = byte & 3;
		i--;
	}
}
