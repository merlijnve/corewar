/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_aux.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 19:30:46 by fmiceli       #+#    #+#                 */
/*   Updated: 2020/09/17 13:32:40 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char		*str_add(char *dst, char *src, int n)
{
	int		carry;

	carry = 0;
	while (n)
	{
		dst[n - 1] = dst[n - 1] + (src[n - 1] - '0') + carry;
		carry = 0;
		if (dst[n - 1] > '9')
		{
			if (n - 2 < 0)
				ft_putendl("Overflow NYI");
			else
			{
				carry = (dst[n - 1] - '0') / 10;
				dst[n - 1] = ((dst[n - 1] - '0') % 10) + '0';
			}
		}
		n--;
	}
	return (dst);
}

char		*str_add_rightside(char *dst, char *src, int n)
{
	while (n)
	{
		dst[n - 1] = dst[n - 1] + (src[n - 1] - '0');
		if (dst[n - 1] > '9')
		{
			if (n - 2 < 0)
				dst[n - 3] += (dst[n - 1] - '0') / 10;
			else
				dst[n - 2] += (dst[n - 1] - '0') / 10;
			dst[n - 1] = ((dst[n - 1] - '0') % 10) + '0';
		}
		n--;
	}
	return (dst);
}

static char	*str_round_up(char *str, int prcs, size_t buff_size)
{
	char	*buff;

	if (!prcs)
	{
		buff = (char*)ft_memalloc(sizeof(char) * buff_size);
		buff = ft_memset(buff, '0', buff_size - 2);
		buff[buff_size - 2] = '1';
		str = str_add(str, buff, (int)(buff_size - 1));
		free(buff);
		return (str);
	}
	buff = (char*)ft_memalloc(sizeof(char) * (prcs + 1));
	buff = ft_memset(buff, '0', prcs - 1);
	buff[prcs - 1] = '1';
	str_add_rightside(ft_strchr(str, '.') + 1, buff, prcs);
	free(buff);
	return (str);
}

char		*str_round(char *str, int prcs)
{
	char	*non_significant;
	char	*ptr;

	non_significant = ft_strchr(str, '.') + 1 + prcs;
	if (*non_significant <= '5')
	{
		if (*non_significant <= '4')
			return (str);
		else if (*(non_significant - (prcs == 0 ? 2 : 1)) % 2 == 0)
		{
			ptr = non_significant + 1;
			while (*ptr == '0')
				ptr++;
			if (*ptr == '\0')
				return (str);
		}
	}
	return (str_round_up(str, prcs, non_significant - str));
}
