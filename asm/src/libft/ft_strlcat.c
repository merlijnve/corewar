/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 11:09:35 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:26 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dlen;
	size_t slen;
	size_t to_copy;

	dlen = ft_strllen(dst, dstsize);
	slen = ft_strlen(src);
	if ((dlen + slen + 1) > dstsize)
		to_copy = dstsize - dlen - 1;
	else if (slen > 0)
		to_copy = slen;
	else
		to_copy = 0;
	if (dlen < dstsize && to_copy > 0)
	{
		ft_memcpy(&dst[dlen], src, to_copy);
		dst[dlen + to_copy] = '\0';
	}
	return (dlen + slen);
}
