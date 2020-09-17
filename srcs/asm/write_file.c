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

	if (fd >= 0)
	{
		code_len = (asmblr->bc.bcp - asmblr->bc.bcdata);
		bzero(box, 16);
		magic = COREWAR_EXEC_MAGICR;
		write(fd, &magic, sizeof(magic));
		write(fd, asmblr->name, PROG_NAME_LENGTH);
		write(fd, &box[4], 4);
		ft_putmembe(box, code_len, 4);
		write(fd, box, 4);
		write(fd, asmblr->comment, COMMENT_LENGTH);
		write(fd, &box[4], 4);
		write(fd, asmblr->bc.bcdata, code_len);
		close(fd);
		printf("Succesfully Assembled: %s\n", asmblr->file_name);
		return (kSuccess);
	}
	return (kErrorOpeningFile);
}
