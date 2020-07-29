/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_max.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:02:45 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/02/03 14:03:15 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long	ft_max(long long x, long long y)
{
	if (x >= y)
		return (x);
	return (y);
}

void		*ft_maxp(void *x, void *y)
{
	if (x >= y)
		return (x);
	return (y);
}
