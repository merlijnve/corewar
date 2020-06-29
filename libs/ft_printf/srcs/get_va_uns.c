/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_uns.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/11 18:22:57 by jboer         #+#    #+#                 */
/*   Updated: 2020/05/22 14:17:23 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*fill_width_u(char *str, t_print *print)
{
	char		*buf;
	size_t		slen;
	char		c;

	slen = (int)ft_strlen(str);
	if (print->width <= (int)slen)
		return (str);
	c = ' ';
	if (print->flags[1] == 1)
		c = '0';
	buf = ft_strnew(print->width);
	ft_memset((void *)buf, c, print->width);
	if (print->flags[3] == 1)
		ft_strncpy(buf, str, slen);
	else
		ft_strncpy(&buf[print->width - slen], str, slen);
	ft_strdel(&str);
	return (buf);
}

static char		*add_precision(char *str, t_print *print)
{
	int		len;
	char	*res;
	char	*head;

	len = ft_strlen(str);
	if (print->prec == 0 && print->value == 0)
		return (ft_strnew(0));
	if (len >= print->prec)
		return (str);
	res = ft_strnew(print->prec);
	head = res;
	res = ft_memset(res, '0', print->prec);
	res = ft_strncpy(&res[print->prec - len], str, len);
	ft_strdel(&str);
	return (head);
}

static void		ui_to_str(unsigned long long n, t_print *print)
{
	char	*str;

	str = ft_ulltoa(n);
	str = add_precision(str, print);
	str = fill_width_u(str, print);
	ft_putstr(str);
	print->printed = ft_strlen(str);
	ft_strdel(&str);
}

void			get_va_uns(t_print *print, va_list ap)
{
	if (print->spec == 0)
		ui_to_str(va_arg(ap, unsigned int), print);
	if (print->spec == 1)
		ui_to_str((unsigned char)va_arg(ap, unsigned int), print);
	if (print->spec == 2)
		ui_to_str((unsigned short)va_arg(ap, unsigned int), print);
	if (print->spec == 3)
		ui_to_str(va_arg(ap, unsigned long), print);
	if (print->spec == 4)
		ui_to_str(va_arg(ap, unsigned long long), print);
}
