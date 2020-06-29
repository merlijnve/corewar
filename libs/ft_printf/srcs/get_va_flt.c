/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_flt.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/27 18:11:16 by jboer         #+#    #+#                 */
/*   Updated: 2020/05/22 14:16:36 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void		move_plusmin(char *str, char c, t_print *print)
{
	int i;

	i = 0;
	if (print->flags[1] == 1 || print->flags[4] == 1)
	{
		if (print->value < 0)
			str[i] = '-';
		if (print->value > 0 && print->flags[4])
			str[i] = ' ';
		if (print->value > 0 && print->flags[2])
			str[i] = '+';
		i++;
		while (str[i] == c)
			i++;
		if (str[i] == '-' || str[i] == ' ' || str[i] == '+')
			str[i] = c;
	}
}

static char		*fill_width_f(char *str, t_print *print)
{
	char		*buf;
	size_t		slen;
	char		c;

	c = ' ';
	if (print->flags[1] == 1)
		c = '0';
	slen = ft_strlen(str);
	buf = ft_strnew(print->width);
	ft_memset((void *)buf, c, print->width);
	if (print->flags[3] == 1)
		ft_strncpy(buf, str, slen);
	else
		ft_strncpy(&buf[print->width - slen], str, slen);
	move_plusmin(buf, c, print);
	return (buf);
}

static char		*set_specials(long double f, t_print *print)
{
	char		*str;

	print->flags[1] = 0;
	if (f == 1.0 / 0.0)
		str = ft_strdup("inf");
	if (f != f)
	{
		str = ft_strdup("nan");
		print->flags[2] = 0;
		print->flags[4] = 0;
	}
	if (f == -1.0 / 0.0)
		str = ft_strdup("-inf");
	return (str);
}

static void		flt_to_str(long double f, t_print *print)
{
	char		*str;
	char		*buf;

	if (f == 1.0 / 0.0 || f != f || f == -1.0 / 0.0)
		str = set_specials(f, print);
	else
		str = ft_fltoa(f, print->prec);
	if (print->prec == 0 && print->flags[0])
		str = ft_straddtoend(str, ".");
	if (f == (long double)-0.0 || f < (long double)0)
		print->value = -1;
	if (f >= (long double)0)
		print->value = 1;
	str = add_flags(str, print);
	if (print->width > (int)ft_strlen(str))
	{
		buf = str;
		str = fill_width_f(str, print);
		ft_strdel(&buf);
	}
	print->printed = ft_strlen(str);
	ft_putstr(str);
}

void			get_va_flt(t_print *print, va_list ap)
{
	if (print->spec == 0 || print->spec == 3)
		flt_to_str((long double)va_arg(ap, double), print);
	if (print->spec == 5)
		flt_to_str(va_arg(ap, long double), print);
}
