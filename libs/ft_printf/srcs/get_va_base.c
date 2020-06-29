/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_base.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/12 12:29:11 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/05/22 14:16:20 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*add_precision(char *str, t_print *print, int base)
{
	int		len;
	char	*res;
	char	*head;

	len = ft_strlen(str);
	if (len >= print->prec)
		return (str);
	if (base == 8)
	{
		res = ft_strnew(print->prec - print->flags[0]);
		head = res;
		res = ft_memset(res, '0', print->prec - print->flags[0]);
		ft_strncpy(&res[print->prec - len - print->flags[0]], str, len);
	}
	else
	{
		res = ft_strnew(print->prec);
		head = res;
		res = ft_memset(res, '0', print->prec);
		ft_strncpy(&res[print->prec - len], str, len);
	}
	ft_strdel(&str);
	return (head);
}

static char		*add_hash(int base, char *str, t_print *print, char *t)
{
	if ((base == 8 && str[0] == '\0') || (base == 8 && print->value != 0))
		t = ft_straddtofront(t, "0");
	else if (base == 16 && print->value != 0)
		t = ft_straddtofront(t, "0x");
	return (t);
}

static void		b_to_str(unsigned long long n, t_print *print)
{
	char		*str;
	int			base;

	print->value = n;
	base = print->fid == 'o' ? 8 : 16;
	str = ft_unbrbase(n, base);
	if (print->value == 0 && print->prec == 0)
	{
		ft_strdel(&str);
		str = ft_strnew(0);
	}
	if ((int)ft_strlen(str) < print->prec - print->flags[0])
		str = add_precision(str, print, base);
	if (print->width > (int)ft_strlen(str))
		str = make_width_base(print, base, str);
	else if (print->flags[0] == 1)
		str = add_hash(base, str, print, str);
	if (print->fid == 'X')
		ft_str_to_uppercase(str);
	ft_putstr(str);
	print->printed = ft_strlen(str);
	ft_strdel(&str);
}

void			get_va_base(t_print *print, va_list ap)
{
	if (print->spec == 0)
		b_to_str((unsigned int)va_arg(ap, unsigned int), print);
	if (print->spec == 1)
		b_to_str((unsigned char)va_arg(ap, unsigned int), print);
	if (print->spec == 2)
		b_to_str((unsigned short)va_arg(ap, unsigned int), print);
	if (print->spec == 3)
		b_to_str(va_arg(ap, unsigned long), print);
	if (print->spec == 4)
		b_to_str(va_arg(ap, unsigned long long), print);
}
