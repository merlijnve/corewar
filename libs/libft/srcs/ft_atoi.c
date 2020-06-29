/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/14 14:37:56 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:55:58 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_calc(int i, const char *str)
{
	int x;
	int y;

	y = 0;
	while (ft_isdigit(str[i]))
	{
		x = str[i] - 48;
		y = y * 10 + x;
		i++;
	}
	return (y);
}

int			ft_atoi(const char *str)
{
	int i;
	int y;
	int neg;

	i = 0;
	neg = 1;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n' \
	|| str[i] == '\r' || str[i] == '\t' || str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg = -1;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
		return (0);
	y = ft_calc(i, str) * neg;
	return (y);
}
