/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: twoerdem <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/23 14:25:35 by twoerdem      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:44 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlchr(char *s, char c, size_t len)
{
	size_t i;

	i = 0;
	while (s[i] != '\0' && i < len)
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (0);
}
