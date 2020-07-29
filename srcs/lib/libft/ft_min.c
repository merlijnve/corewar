/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_min.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/03 14:00:29 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/02/03 14:01:23 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

long long	ft_min(long long x, long long y)
{
	if (x <= y)
		return (x);
	return (y);
}

void		*ft_minp(void *x, void *y)
{
	if (x <= y)
		return (x);
	return (y);
}
