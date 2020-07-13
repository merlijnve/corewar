/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:15 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	t_index			idx;
	unsigned char	*ldst;
	unsigned char	*lsrc;

	ldst = (unsigned char*)dst;
	lsrc = (unsigned char*)src;
	idx = 0;
	while (idx < n)
	{
		ldst[idx] = lsrc[idx];
		idx++;
	}
	return (dst);
}
