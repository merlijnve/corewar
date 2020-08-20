/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hdictnew.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 09:26:23 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/06/24 09:26:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_hdict			*ft_hdictnew(size_t size)
{
	t_hdict *dict;

	dict = ft_memalloc(sizeof(t_hdict));
	if (dict == NULL)
		return (NULL);
	dict->size = size;
	dict->buckets = ft_memalloc(sizeof(t_list *) * size);
	if (dict->buckets == NULL)
	{
		free(dict);
		return (NULL);
	}
	return (dict);
}
