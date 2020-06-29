/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strnstr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/17 12:56:29 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 16:00:19 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	nlen;
	int		x;
	char	*s;
	size_t	alen;
	size_t	hlen;

	alen = (int)len;
	x = 0;
	nlen = ft_strlen(needle);
	hlen = ft_strlen(haystack);
	if (nlen > len)
		return (NULL);
	if (nlen == 0 || haystack == needle)
		return ((char *)haystack);
	while (nlen <= hlen && haystack[x + nlen - 1] \
	!= '\0' && len > 0 && (nlen + x - 1) != alen)
	{
		s = (char *)&haystack[x];
		if (ft_strncmp(needle, s, nlen) == 0)
			return (s);
		else
			x++;
		len--;
	}
	return (NULL);
}
