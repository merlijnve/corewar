/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 20:10:25 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:26 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memrchr(const void *s, int c, size_t n)
{
	t_index			idx;
	unsigned char	*mem;

	if (s == NULL || n == 0)
		return (NULL);
	mem = (unsigned char*)s;
	idx = n;
	while (idx > 0)
	{
		if (mem[idx - 1] == (unsigned char)c)
			return ((char *)&mem[idx - 1]);
		idx--;
	}
	return (NULL);
}
