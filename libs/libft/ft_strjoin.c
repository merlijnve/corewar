/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:18 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:26 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	len2;
	char	*dest;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	dest = ft_strnew(len1 + len2);
	if (dest != NULL)
	{
		ft_strcpy(dest, s1);
		ft_strcpy(&dest[len1], s2);
	}
	return (dest);
}
