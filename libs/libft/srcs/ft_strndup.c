/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strndup.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/08 20:09:01 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 16:00:14 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strndup(const char *src, size_t size)
{
	char	*dup;
	size_t	length;
	size_t	x;

	x = 0;
	length = 1 + size;
	dup = (char *)malloc(size * sizeof(char));
	if (dup == NULL)
		return (NULL);
	while (x < length && x < size)
	{
		dup[x] = src[x];
		x++;
		dup[x + 1] = '\0';
	}
	return (dup);
}
