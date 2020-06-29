/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_natoi.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/05 15:22:51 by jboer         #+#    #+#                 */
/*   Updated: 2020/04/14 15:58:14 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_atoipm(const char *str, int neg)
{
	while (*str == '+' || *str == '-')
	{
		if (neg == -1)
			return (0);
		str++;
		if (*str == '+')
			return (0);
	}
	return (1);
}

int			ft_natoi(const char *str, int n)
{
	int neg;
	int nb;
	int pm;

	neg = 1;
	nb = 0;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\r' ||
	*str == '\f' || *str == '\v')
		str++;
	if (*str == '-')
		neg = -1;
	if (neg == -1)
		str++;
	pm = ft_atoipm(str, neg);
	if (pm == 0)
		return (0);
	if (*str == '+')
		str++;
	while (*str && *str >= '0' && *str <= '9' && n > 0)
	{
		nb = nb * 10 + (*str - 48);
		str++;
		n--;
	}
	return (nb * neg);
}
