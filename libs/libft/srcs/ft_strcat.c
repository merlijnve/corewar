/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcat.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/10 19:36:40 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:58:59 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t x;
	size_t y;

	y = 0;
	x = ft_strlen(s1);
	while (s2[y] != '\0')
	{
		s1[x] = s2[y];
		y++;
		x++;
	}
	s1[x] = '\0';
	return (s1);
}
