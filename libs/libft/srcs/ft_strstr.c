/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/15 15:48:13 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 16:00:30 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	nlen;
	size_t	hlen;
	int		x;
	char	*s;

	x = 0;
	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (nlen == 0 || haystack == needle)
		return ((char *)&haystack[x]);
	while (nlen < hlen && haystack[x + nlen - 1] != '\0')
	{
		s = (char *)&haystack[x];
		if (ft_strncmp(needle, s, nlen) == 0)
			return (s);
		else
			x++;
	}
	return (NULL);
}
