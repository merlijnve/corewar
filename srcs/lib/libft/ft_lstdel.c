/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstdel.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/07 19:03:07 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/08 14:19:51 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *next;
	t_list *tmp;

	tmp = *alst;
	while (tmp != NULL)
	{
		next = tmp->next;
		ft_lstdelone(&tmp, del);
		free(tmp);
		tmp = next;
	}
	*alst = NULL;
}
