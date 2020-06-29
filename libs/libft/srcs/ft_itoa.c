/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 13:23:24 by jboer         #+#    #+#                 */
/*   Updated: 2020/04/14 15:56:51 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_itoa(int n)
{
	int		intlen;
	char	*strn;
	int		i;

	i = 0;
	intlen = ft_intlen(n);
	strn = (char*)malloc(sizeof(char) * (intlen + 1));
	if (strn == NULL)
		return (NULL);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	strn[intlen] = '\0';
	if (n < 0)
	{
		n = n * -1;
		intlen--;
		strn[i] = '-';
		i = 1;
	}
	strn = ft_intos(strn, intlen, i, n);
	return (strn);
}
