/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hdictadd.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 09:25:52 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/06/24 09:25:53 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static t_hlist	*pack_item(t_hash hash, void *item)
{
	t_hpair *pair;
	t_hlist	*link;

	pair = ft_memalloc(sizeof(t_hpair));
	link = ft_memalloc(sizeof(t_list));
	if (pair == NULL || link == NULL)
	{
		free(pair);
		free(link);
		return (NULL);
	}
	pair->key = hash;
	pair->value = item;
	link->content = pair;
	return link;
}

t_lft_ret		ft_hdictadd(t_hdict *dict, t_hash key, void *item)
{
	t_hash	lkey;
	t_hlist	**litem;
	t_hlist	*head;
	t_hlist	*part;

	if (ft_hdictget(dict, key) != NULL)
	{
		return (kLFTDuplicateError);
	}
	part = pack_item(key, item);
	if (part == NULL)
		return (kLFTAllocError);
	lkey = key % dict->size;
	litem = &dict->buckets[lkey];
	head = dict->buckets[lkey];
	*litem = part;
	part->next = head;
	return (kLFTSucces);
}
