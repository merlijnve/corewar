/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dictget.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/10 15:46:40 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/10 17:23:52 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict	*ft_dictget(t_dict *dict, int key)
{
	while (dict != NULL && dict->pair != NULL)
	{
		if (dict->pair->key == key)
			return (dict);
		dict = dict->next;
	}
	return (NULL);
}
