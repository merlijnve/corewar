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

t_ret	write_file(t_asm *asmb, int fd, uint32_t magic)
{
	uint8_t		box[16];
	ssize_t		ret;

	ret = 0;
	if (fd >= 0)
	{
		bzero(box, 16);
		ret = write(fd, &magic, sizeof(magic));
		if (ret != -1)
			ret = write(fd, asmb->name, PROG_NAME_LENGTH);
		if (ret != -1)
			ret = write(fd, &box[4], 4);
		ft_putmembe(box, (asmb->bc.bcp - asmb->bc.bcdata), 4);
		if (ret != -1)
			ret = write(fd, box, 4);
		if (ret != -1)
			ret = write(fd, asmb->comment, COMMENT_LENGTH);
		if (ret != -1)
			ret = write(fd, &box[4], 4);
		if (ret != -1)
			ret = write(fd, asmb->bc.bcdata, (asmb->bc.bcp - asmb->bc.bcdata));
		close(fd);
		return (ret != -1 ? kSuccess : kErrorOpeningFile);
	}
	return (kErrorOpeningFile);
}
