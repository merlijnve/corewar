/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_dictremove.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/10 15:46:40 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/10 17:23:52 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Does not assure that links keep the same adress
*/

void	ft_dictremove(t_dict *dict, int key)
{
	t_dict	*next_one;

	dict = ft_dictget(dict, key);
	if (dict != NULL)
	{
		free(dict->pair->value);
		free(dict->pair);
		next_one = dict->next;
		if (next_one != NULL)
		{
			dict->pair = next_one->pair;
			dict->next = next_one->next;
			free(next_one);
		}
		else
		{
			dict->pair = NULL;
			dict->next = NULL;
		}
	}
}
