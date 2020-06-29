/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 14:46:50 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:58:09 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*dst2;
	char	*src2;

	src2 = (char *)src;
	dst2 = (char *)dst;
	i = 0;
	if (src >= dst)
	{
		while (len > i)
		{
			dst2[i] = src2[i];
			i++;
		}
	}
	else
	{
		while (len > i)
		{
			dst2[len - 1] = src2[len - 1];
			len--;
		}
	}
	return (dst);
}
