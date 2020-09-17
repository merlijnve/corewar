/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hdictfree.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 09:26:01 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/06/24 09:26:02 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_hdictfree(t_hdict *dict, void (*del)(void*))
{
	t_index idx;
	t_hlist *next;
	t_hlist *this;
	t_hlist *bucket;

	idx = 0;
	while (idx < dict->size)
	{
		bucket = dict->buckets[idx];
		this = bucket;
		while (this != NULL)
		{
			next = this->next;
			del(this->content->value);
			free(this->content);
			free(this);
			this = next;
		}
		idx++;
	}
	free(dict->buckets);
	free(dict);
}
