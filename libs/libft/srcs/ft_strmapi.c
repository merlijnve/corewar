/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 12:33:20 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:50 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		str = ft_strdup((char *)s);
		if (str == NULL)
			return (NULL);
		while (str[i] != '\0')
		{
			str[i] = f(i, str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
