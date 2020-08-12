/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_arguments.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/12 14:41:11 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/12 18:47:33 by merlijn       ########   odam.nl         */
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

static void	get_argument_types(int byte, t_cursor *cursor)
{
	int	i;

	i = 2;
	if ((byte & 3) != 0)
		vm_error(ERR_BAD_ENC);
	while (i >= 0)
	{
		byte = byte >> 2;
		cursor->args[i].type = byte & 3;
		i--;
	}
}

void		get_arguments(char *mem, t_cursor *cursor)
{
	int	encoding_byte;

	encoding_byte = mem[(cursor->pos + 1) % MEM_SIZE];
	get_argument_types(encoding_byte, cursor);
}
