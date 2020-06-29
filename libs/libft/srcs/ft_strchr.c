/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 16:24:26 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:01 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	if (c == '\0')
	{
		if (s[i] == '\0')
			return ((char *)&s[i]);
	}
	else
	{
		while (s[i] != '\0')
		{
			if (s[i] == c)
				return ((char *)&s[i]);
			i++;
		}
	}
	while (c == '\0')
	{
		if (s[i] == '\0')
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}
