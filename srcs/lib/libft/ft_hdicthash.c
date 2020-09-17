/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_hdicthash.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 10:27:41 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/06/24 10:27:43 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_hash	ft_hdicthash(char *data, size_t size)
{
	t_hash	hash;
	t_index idx;

	hash = 0;
	idx = 0;
	if (size > 0)
	{
		while (idx < size)
		{
			hash = (int)(*(data + idx)) + (hash << 6) + (hash << 16) - hash;
			idx++;
		}
	}
	else
	{
		while (data[idx] != '\0')
		{
			hash = (int)(*(data + idx)) + (hash << 6) + (hash << 16) - hash;
			idx++;
		}
	}
	return (hash);
}
