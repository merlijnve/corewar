/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_binary.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 14:04:39 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/05/22 14:16:27 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		bin_to_str(unsigned long long l, t_print *print)
{
	char	*str;
	char	fill;
	char	*res;

	fill = print->flags[1] == 1 ? '0' : ' ';
	str = ft_unbrbase(l, 2);
	res = str;
	print->width = print->width > print->prec ? print->width : print->prec;
	if (print->width > (int)ft_strlen(str))
	{
		res = ft_strnew(print->width);
		ft_memset((void *)res, fill, print->width);
		if (print->flags[3] == 1)
			res = ft_straddtofront(res, str);
		else
			res = ft_straddtoend(res, str);
		ft_strdel(&str);
	}
	ft_putstr(res);
}

void		get_va_binary(t_print *print, va_list ap)
{
	if (print->spec == 0)
		bin_to_str(va_arg(ap, unsigned int), print);
	if (print->spec == 1)
		bin_to_str((unsigned char)va_arg(ap, unsigned int), print);
	if (print->spec == 2)
		bin_to_str((unsigned short)va_arg(ap, unsigned int), print);
	if (print->spec == 3)
		bin_to_str(va_arg(ap, unsigned long), print);
	if (print->spec == 4)
		bin_to_str(va_arg(ap, unsigned long long), print);
}
