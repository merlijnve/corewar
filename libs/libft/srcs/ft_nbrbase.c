/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_nbrbase.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/06 13:43:08 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:58:16 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_nbrbase_loop(long long l, int b, char *res)
{
	int		i;
	int		m;

	i = 67;
	res[i] = '\0';
	while (l > 0)
	{
		i--;
		m = l % b;
		if (m >= 0 && m <= 9)
			res[i] = m + '0';
		else
			res[i] = m + 'a' - 10;
		l = l / b;
	}
	return (i);
}

char		*ft_nbrbase(long long l, int b)
{
	char	*res;
	int		i;
	char	*s;

	res = (char *)malloc(sizeof(char) * 68);
	if (l < 0)
	{
		i = ft_nbrbase_loop(l * -1, b, res);
		i--;
		res[i] = '-';
	}
	else
		i = ft_nbrbase_loop(l, b, res);
	if (l == 0)
	{
		i = 66;
		res[i] = '0';
	}
	s = ft_strdup(&res[i]);
	ft_strdel(&res);
	return (s);
}
