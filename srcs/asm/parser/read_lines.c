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

t_ret	read_lines(char *file, t_list **lines)
{
	t_ret			ret;
	t_index			idx;
	t_list			*item;
	char			*last;

	ret = kSuccess;
	idx = 0;
	last = file;
	while (file[idx] != '\0' && ret == kSuccess)
	{
		if (file[idx] == '\n') {
			item = ft_memalloc(sizeof(t_list));
			if (item == NULL)
				return (kErrorAlloc);
			item->content = ft_strnew((&file[idx] - last) + 1);
			ft_memcpy(item->content, last, &file[idx] - last);
			item->next = *lines;
			*lines = item;
			last = &file[idx + 1];
		}
		idx++;
	}
	return (ret);
}
