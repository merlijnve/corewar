/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 13:00:11 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:55 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long x;

	x = 0;
	if (n == 0)
		return (0);
	while (s1[x] != '\0' && s2[x] != '\0' && s1[x] == s2[x] && x < (n - 1))
		x++;
	return (((unsigned char)s1[x]) - ((unsigned char)s2[x]));
}
