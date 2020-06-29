/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/29 15:24:30 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:57:40 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		ft_lstncpy(t_list *lst, t_list *new,
int *len, t_list *(*f)(t_list *elem))
{
	if (*len < 2)
		return ;
	new->next = f(lst->next);
	*len = *len - 1;
	ft_lstncpy(lst->next, new->next, len, f);
}

static void		ft_lstcount(t_list *lst, int *len)
{
	if (lst == NULL)
		return ;
	*len = *len + 1;
	ft_lstcount(lst->next, len);
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	int		*len;
	t_list	*new;

	len = (int *)malloc(sizeof(int));
	*len = 0;
	ft_lstcount(lst, len);
	new = f(lst);
	ft_lstncpy(lst, new, len, f);
	free(len);
	return (new);
}
