/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstnew.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 13:53:38 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 20:45:03 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		fill_item(void *content, size_t size, t_list *list)
{
	list->content = content;
	list->content_size = size;
	list->next = NULL;
}

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	list = ft_memalloc(sizeof(t_list));
	if (content == NULL && list != NULL)
		fill_item(NULL, 0, list);
	else if (list != NULL)
	{
		list->content = ft_memalloc(content_size);
		if (list->content != NULL)
		{
			list->content_size = content_size;
			ft_memcpy(list->content, content, content_size);
		}
		else
		{
			ft_memdel((void **)&(list));
			list->content_size = 0;
		}
	}
	return (list);
}
