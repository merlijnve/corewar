/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_lines.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 18:24:50 by floris        #+#    #+#                 */
/*   Updated: 2020/06/24 18:24:52 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "input_parser.h"

t_ret	read_lines(int fd, t_list **lines)
{
	t_ret			ret;
	char			*line;
	t_list			*item;

	ret = kSuccess;
	while (get_next_line(fd, &line) > 0 && ret == kSuccess)
	{
		item = ft_memalloc(sizeof(t_list));
		if (item == NULL)
			return (kErrorAlloc);
		if (line)
			item->content = ft_strtrim(line);
		free(line);
		item->next = *lines;
		*lines = item;
	}
	return (ret);
}

