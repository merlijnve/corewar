/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 12:39:14 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 16:00:27 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	index;
	size_t	length;

	if (s == NULL)
		return (NULL);
	index = 0;
	i = 0;
	length = ft_strdcount(s, c);
	res = (char **)malloc((length + 1) * sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[length] = NULL;
	while (i < length)
	{
		res[i] = ft_strnew(ft_strdlen(&s[index], c));
		if (res[i] == NULL)
			return (NULL);
		index = ft_strdcpy(res[i], s, c, index);
		i++;
	}
	return (res);
}
