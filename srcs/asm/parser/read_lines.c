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

static t_ret	add_lines(t_list **lines, char *file, char *last, t_index idx)
{
	t_list	*item;

	item = ft_memalloc(sizeof(t_list));
	if (item == NULL)
		return (kErrorAlloc);
	item->content = ft_memalloc((&file[idx] - last) + 1);
	if (item->content == NULL)
	{
		free(item);
		return (kErrorAlloc);
	}
	item->content_size = (*lines != NULL ? (*lines)->content_size + 1 : 1);
	ft_memcpy(item->content, last, (&file[idx] - last));
	item->next = *lines;
	*lines = item;
	return (kSuccess);
}

t_ret			read_lines(char *file, t_list **lines)
{
	t_ret			ret;
	t_index			idx;
	char			*last;

	idx = 0;
	last = file;
	ret = kSuccess;
	while (file[idx] != '\0' && ret == kSuccess)
	{
		if (file[idx] == '\n') {
			ret = add_lines(lines, file, last, idx);
			last = &file[idx + 1];
		}
		idx++;
	}
	if (ret == kSuccess && idx >= 1)
		ret = add_lines(lines, file, last, idx);
	if (ret == kSuccess)
		ft_lstrev(lines);
	return (ret);
}
