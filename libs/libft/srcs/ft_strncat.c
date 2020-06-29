/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/11 12:03:10 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:53 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t			x;
	size_t			y;

	y = 0;
	x = ft_strlen(s1);
	while (s2[y] != '\0' && y < n)
	{
		s1[x] = s2[y];
		x++;
		y++;
	}
	s1[x] = '\0';
	return (s1);
}
