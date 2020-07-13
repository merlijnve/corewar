/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_rhs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 19:29:43 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/12/01 19:29:44 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdbool.h>
#include <stdlib.h>
#include "float_aux.h"
#include "ft_printf_types.h"

static char	*str_half(char *str, int len)
{
	int	i;
	int	carry;
	int	carry_tmp;

	i = 0;
	carry = false;
	while (i < len)
	{
		carry_tmp = false;
		if ((str[i] - '0') % 2 == 1)
			carry_tmp = true;
		str[i] = ((str[i] - '0') / 2) + (carry ? '5' : '0');
		i++;
		carry = carry_tmp;
	}
	return (str);
}

static char	*init_buff(char *buff, int len)
{
	buff = ft_memset(buff, '0', len);
	buff[0] = '5';
	return (buff);
}

char		*set_right_of_dot(
	char *str, int size, t_ld_parts ld, unsigned long i)
{
	int		exp;
	char	*buff;
	char	*frac_addr;
	int		len;

	frac_addr = ft_strchr(str, '.') + 1;
	len = (int)(size - (frac_addr - str));
	buff = (char *)ft_memalloc(sizeof(char) * (len + 1));
	while (i < LD_MANTISSA_BITS)
	{
		if ((ld.m & (1UL << (LD_MANTISSA_BITS - 1UL - i))))
		{
			exp = (int)((ld.s_exp & LD_EXP) - LD_EXP_BIAS + 1 - i);
			buff = init_buff(buff, len);
			while (exp < 0)
			{
				buff = str_half(buff, len);
				exp++;
			}
			frac_addr = str_add_rightside(frac_addr, buff, len);
		}
		i++;
	}
	free(buff);
	return (str);
}
