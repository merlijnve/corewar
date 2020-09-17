/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_file.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "input_parser.h"

static void		*ft_realloc
	(void *buff, const void *badd, size_t sold, size_t sadd)
{
	void *new;

	new = ft_memalloc(sold + sadd + 1);
	if (new != NULL)
	{
		ft_memcpy(new, buff, sold);
		ft_memcpy(new + sold, badd, sadd);
		ft_memset(new + sold + sadd, '\0', 1);
	}
	free(buff);
	return (new);
}

t_ret			read_file(int fd, char **buffer)
{
	char	part[BUFF_SIZE];
	t_ret	ret;
	ssize_t	rret;
	size_t	bsize;

	ret = kSuccess;
	rret = 1;
	bsize = 0;
	while (rret > 0)
	{
		rret = read(fd, part, BUFF_SIZE);
		if (rret > 0)
		{
			*buffer = ft_realloc(*buffer, part, bsize, rret);
			if (*buffer == NULL)
				return (kErrorAlloc);
			bsize += rret;
		}
	}
	if (*buffer == NULL)
		return (kErrorEmptyFile);
	return (ret);
}
