/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:19 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:27 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t s1len;
	size_t s2len;
	size_t to_copy;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	if (s2len >= n)
		to_copy = n;
	else
		to_copy = s2len;
	ft_memcpy(&s1[s1len], s2, to_copy);
	s1[s1len + to_copy] = '\0';
	return (s1);
}
