/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 13:44:48 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:57:55 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	unsigned char	*dst2;
	unsigned char	*src2;
	unsigned char	bt;

	bt = (unsigned char)c;
	src2 = (unsigned char *)src;
	dst2 = (unsigned char *)dst;
	i = 0;
	while (n > 0)
	{
		dst2[i] = src2[i];
		if (src2[i] == bt)
			return (&dst[i + 1]);
		n--;
		i++;
	}
	return (NULL);
}
