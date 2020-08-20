/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:15 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t len)
{
	t_index			idx;
	unsigned char	*ldst;
	unsigned char	*lsrc;

	ldst = ((unsigned char*)dst);
	lsrc = ((unsigned char*)src);
	idx = 0;
	while (idx < len)
	{
		ldst[idx] = lsrc[idx];
		if (lsrc[idx] == (unsigned char)c)
			return (&ldst[idx + 1]);
		idx++;
	}
	return (NULL);
}
