/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_arguments.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 14:41:11 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/12 15:19:32 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	GET_ARGUMENT_TYPES
**	Uses bitwise operators to split the encoding byte
**	into all three types
**	T_REG = 0x01 = 1
**	T_DIR = 0x10 = 2
**	T_IND = 0x11 = 3
**	empty = 0x00 = 0
*/

int		get_argument_types(int byte, t_cursor *cursor)
{
	int	i;

	i = 2;

	if (byte & 3 != 0)
		return (ERR_BAD_ENC);
	while (i >= 0)
	{
		byte = byte >> 2;
		cursor->args[i].type = byte & 3;
		i--;
	}
	return (OK);
}

int		get_argument_values(char *mem, t_cursor *cursor)
{
	get_direct_value();
	get_indirect_value();
}

void	get_arguments(char *mem, t_cursor *cursor)
{
	int	encoding_byte;

	encoding_byte = mem[(cursor->pos + 1) % MEM_SIZE];
	if (get_argument_types(encoding_byte, cursor) != OK)
		vm_error(ERR_BAD_ENC);
	get_argument_values(mem, cursor);
}
