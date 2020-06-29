/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 14:14:25 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:39 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		start;

	if (s1 != NULL && s2 != NULL)
	{
		i = 0;
		str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		if (str == NULL)
			return (NULL);
		while (s1[i] != '\0')
		{
			str[i] = s1[i];
			i++;
		}
		start = i;
		i = 0;
		while (s2[i] != '\0')
		{
			str[start + i] = s2[i];
			i++;
		}
		return (str);
	}
	return (NULL);
}
