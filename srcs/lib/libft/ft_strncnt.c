/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncnt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 10:50:06 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/06/12 10:50:08 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strncnt(const char *s, int c, size_t len)
{
	t_index		idx;
	size_t		cnt;

	idx = 0;
	cnt = 0;
	while (s[idx] != '\0' && idx < len)
	{
		if (s[idx] == c)
			cnt++;
		idx++;
	}
	return (cnt);
}
