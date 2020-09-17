/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hdictget.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 09:26:12 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/06/24 09:26:14 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_hdictget(t_hdict *dict, t_hash key)
{
	t_hlist	*bucket;

	bucket = dict->buckets[key % dict->size];
	while (bucket != NULL && bucket->content->key != key)
		bucket = bucket->next;
	if (bucket == NULL)
		return (bucket);
	else
		return (bucket->content->value);
}
