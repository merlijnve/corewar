/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_ulltoa.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 13:16:37 by jboer         #+#    #+#                 */
/*   Updated: 2020/04/14 16:00:46 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char		*ft_ulltoa(unsigned long long n)
{
	int		intlen;
	char	*strn;

	intlen = ft_ullintlen(n);
	strn = (char *)malloc(sizeof(char) * (intlen + 1));
	if (strn == NULL)
		return (NULL);
	strn[intlen] = '\0';
	while (intlen > 0)
	{
		strn[intlen - 1] = (n % (unsigned long long)10) + '0';
		n = n / (unsigned long long)10;
		intlen--;
	}
	return (strn);
}
