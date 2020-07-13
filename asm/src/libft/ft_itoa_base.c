/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa_base.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 18:54:33 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	char_for_number_base(unsigned int n)
{
	if (n <= 9)
		return ('0' + n);
	else
		return ('A' + n - 10);
}

static void	ft_strnbr_base_cl
	(unsigned long long nbr, unsigned int base, char *dst, size_t len)
{
	t_index	idx;

	idx = len;
	while (nbr >= 1)
	{
		dst[idx - 1] = char_for_number_base(nbr % base);
		idx--;
		nbr /= base;
	}
}

char		*ft_itoa_base(long long n, unsigned int base)
{
	char	*number;
	size_t	len;

	if (n == 0)
		return (ft_strdup("0"));
	else
	{
		if (n < 0)
			len = ft_log(base, (unsigned long long)-n) + 2;
		else
			len = ft_log(base, n) + 1;
	}
	number = (char *)ft_memalloc(len + 1);
	if (!number)
		return (number);
	if (n < 0)
		number[0] = '-';
	ft_strnbr_base_cl(n < 0 ? (unsigned long long)-n :
		(unsigned long long)n, base, number, len);
	return (number);
}
