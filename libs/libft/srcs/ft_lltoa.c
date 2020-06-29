/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lltoa.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 19:39:56 by jboer         #+#    #+#                 */
/*   Updated: 2020/04/14 15:56:56 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_lltoa(long long int n)
{
	int		intlen;
	char	*strn;
	int		i;

	i = 0;
	intlen = ft_llintlen(n);
	strn = ft_strnew(intlen);
	if (strn == NULL)
		return (NULL);
	if (n < (long long)0)
	{
		strn[intlen - 1] = (n % 10) * -1 + '0';
		n = (n / 10);
		n = n * -1;
		intlen = intlen - 2;
		strn[0] = '-';
		i = 1;
	}
	strn = ft_longtos(strn, intlen, i, n);
	return (strn);
}
