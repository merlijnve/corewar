/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hdictremove.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 09:26:33 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/06/24 09:26:35 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_hdictremove(t_hdict *dict, t_hash key, void(*del)(void*))
{
	t_hlist	**head;
	t_hlist *bc;

	head = &(dict->buckets[key % dict->size]);

	while (*head != NULL && (*head)->content->key != key)
		head = &((*head)->next);

	if (*head == NULL)
		return ; // error
	else
	{
		bc = (*head)->next;
		del((*head)->content->value);
		free((*head)->content);
		free(*head);
		*head = bc;
	}
}
