/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dictadd.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/10 15:12:48 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/10 17:23:52 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*ft_dictadd(t_dict *dict, int key, void *content)
{
	if (ft_dictget(dict, key) != NULL)
		ft_dictremove(dict, key);
	while (dict->pair != NULL)
	{
		while (dict->next != NULL)
			dict = dict->next;
		dict->next = ft_dictnew();
		dict = dict->next;
	}
	if (dict != NULL)
	{
		dict->pair = (t_kvpair *)ft_memalloc(sizeof(t_kvpair));
		if (dict->pair != NULL)
		{
			dict->pair->key = key;
			dict->pair->value = content;
		}
	}
	return (dict);
}
