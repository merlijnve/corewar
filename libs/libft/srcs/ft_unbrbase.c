/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_unbrbase.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/27 17:08:00 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 16:00:51 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_unbrbase_loop(unsigned long long l, int b, char *res)
{
	int	i;
	int m;

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

char		*ft_unbrbase(unsigned long long l, int b)
{
	char	*res;
	int		i;
	char	*s;

	res = ft_strnew(68);
	i = ft_unbrbase_loop(l, b, res);
	if (l == 0)
	{
		i = 66;
		res[i] = '0';
	}
	s = ft_strdup(&res[i]);
	ft_strdel(&res);
	return (s);
}
