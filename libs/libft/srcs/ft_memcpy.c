/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 11:52:23 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:58:03 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*dst2;
	char	*src2;

	src2 = (char *)src;
	dst2 = (char *)dst;
	i = 0;
	while (n > 0)
	{
		dst2[i] = src2[i];
		n--;
		i++;
	}
	return (dst);
}
