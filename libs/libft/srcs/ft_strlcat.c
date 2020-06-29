/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:15:31 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:41 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			x;
	size_t			y;
	size_t			res;

	y = 0;
	x = 0;
	while (dst[x] != '\0' && x < size)
		x++;
	res = x;
	if (size == 0)
		return (res + ft_strlen(src));
	while (src[y] != '\0' && x < (size - 1))
	{
		dst[x] = src[y];
		x++;
		y++;
	}
	if (x < size && size > 0)
		dst[x] = '\0';
	res = res + ft_strlen(src);
	return (res);
}
