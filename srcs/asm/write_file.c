/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_file.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:41:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/08 14:41:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "write_file.h"

t_ret	write_file(t_asm *asmblr, int fd, t_error *error)
{
	uint32_t	magic;
	uint8_t		box[16];
	size_t		code_len;

	code_len = (asmblr->bytecode.bcpoint - asmblr->bytecode.bytecode);
	bzero(box, 16);
	magic = COREWAR_EXEC_MAGICR;
	write(fd, &magic , sizeof(magic));
	write(fd, asmblr->name, PROG_NAME_LENGTH + 4);
	ft_putmembe(box, code_len, 4);
	write(fd, box, 4);
	write(fd, asmblr->comment, COMMENT_LENGTH + 4);
	write(fd, asmblr->bytecode.bytecode, code_len);
	return (kSuccess);
}
