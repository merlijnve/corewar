/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 19:57:03 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	t_index			idx;
	unsigned char	*mem;

	mem = (unsigned char*)s;
	idx = 0;
	while (idx < n)
	{
		if (mem[idx] == (unsigned char)c)
			return ((char *)&mem[idx]);
		idx++;
	}
	return (NULL);
}

void	*ft_memrnchr(const void *s, int start, int end, size_t n)
{
	t_index			idx;
	unsigned char	*mem;

	mem = (unsigned char*)s;
	idx = 0;
	while (idx < n)
	{
		if (mem[idx] >= start && mem[idx] <= end)
			return ((char *)&mem[idx]);
		idx++;
	}
	return (NULL);
}

void	*ft_memvchr(const void *s, int c, size_t n, size_t fwidth)
{
	t_index			idx;
	unsigned char	*mem;

	mem = (unsigned char*)s;
	idx = 0;
	while (idx < n * fwidth)
	{
		if (mem[idx] == (unsigned char)c)
			return ((char *)&mem[idx]);
		idx += fwidth;
	}
	return (NULL);
}
