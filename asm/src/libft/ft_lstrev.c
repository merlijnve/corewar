/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstrev.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <marvin@42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 18:23:33 by floris        #+#    #+#                 */
/*   Updated: 2020/06/24 18:23:35 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **lst)
{
	t_list *current;
	t_list *next;
	t_list *prev;

	current = *lst;
	next = NULL;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*lst = prev;
}
