/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 12:18:18 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 16:00:01 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s != NULL && f != NULL)
	{
		i = 0;
		str = ft_strdup((char *)s);
		if (str == NULL)
			return (NULL);
		while (str[i] != '\0')
		{
			str[i] = f(str[i]);
			i++;
		}
		return (str);
	}
	return (NULL);
}
