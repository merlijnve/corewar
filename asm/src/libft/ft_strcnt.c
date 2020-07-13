/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcnt.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 10:49:53 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/06/12 10:49:54 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcnt(const char *s, int c)
{
	t_index		idx;
	size_t		cnt;

	idx = 0;
	cnt = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == c)
			cnt++;
		idx++;
	}
	return (cnt);
}
