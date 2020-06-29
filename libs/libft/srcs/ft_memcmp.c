/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 17:24:11 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:58:01 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			x;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	x = 0;
	if (n == 0)
		return (0);
	while (ss1[x] == ss2[x] && x < (n - 1))
		x++;
	return (ss1[x] - ss2[x]);
}
