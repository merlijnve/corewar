/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:19 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:27 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*dst;
	size_t		len;
	t_index		idx;

	len = ft_strlen(s);
	dst = ft_strnew(len);
	if (dst == NULL)
		return (dst);
	idx = 0;
	while (idx < len)
	{
		dst[idx] = f((unsigned int)idx, s[idx]);
		idx++;
	}
	return (dst);
}
