/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_struct.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 18:43:55 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/05/22 14:15:58 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*check_width_prec(t_print *print, char *fmt, va_list ap)
{
	if (*fmt == '*')
	{
		print->width = va_arg(ap, int);
		fmt++;
	}
	if (*fmt >= '1' && *fmt <= '9')
	{
		print->width = ft_atoi(fmt);
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
	}
	if (*fmt == '.')
	{
		fmt++;
		if (*fmt == '*')
		{
			print->prec = va_arg(ap, int);
			fmt++;
		}
		else
			print->prec = ft_atoi(fmt);
		while (*fmt >= '0' && *fmt <= '9')
			fmt++;
	}
	return (fmt);
}

static char		*check_flags(t_print *print, char *fmt)
{
	while (*fmt == '#' || *fmt == '0' || *fmt == '+' || *fmt == '-' ||
	*fmt == ' ')
	{
		if (*fmt == '#')
			print->flags[0] = 1;
		if (*fmt == '0')
			print->flags[1] = 1;
		if (*fmt == '+')
			print->flags[2] = 1;
		if (*fmt == '-')
			print->flags[3] = 1;
		if (*fmt == ' ')
			print->flags[4] = 1;
		fmt++;
	}
	return (fmt);
}

static char		*check_spec(t_print *print, char *fmt)
{
	if (*fmt == 'h')
		print->spec = 2;
	if (*fmt == 'h' && fmt[1] == 'h')
		print->spec = 1;
	if (*fmt == 'l')
		print->spec = 3;
	if (*fmt == 'l' && fmt[1] == 'l')
		print->spec = 4;
	if (*fmt == 'L')
		print->spec = 5;
	while (*fmt == 'l' || *fmt == 'L' || *fmt == 'h')
		fmt++;
	return (fmt);
}

static char		*check_fid(t_print *print, char *fmt)
{
	if (*fmt == '%' || *fmt == 'd' || *fmt == 'i' || *fmt == 'u' ||
	*fmt == 'o' || *fmt == 'x' || *fmt == 'X' || *fmt == 'f' ||
	*fmt == 'F' || *fmt == 'e' || *fmt == 'E' || *fmt == 'g' ||
	*fmt == 'G' || *fmt == 'a' || *fmt == 'A' || *fmt == 'c' ||
	*fmt == 's' || *fmt == 'p' || *fmt == 'n' || *fmt == 'b')
		print->fid = *fmt;
	fmt++;
	return (fmt);
}

char			*fill_struct(t_print *print, char *fmt, va_list ap)
{
	fmt++;
	fmt = check_flags(print, fmt);
	print->prec = -1;
	fmt = check_width_prec(print, fmt, ap);
	if (print->width < 0)
	{
		print->flags[3] = 1;
		print->width = print->width * -1;
	}
	fmt = check_spec(print, fmt);
	fmt = check_fid(print, fmt);
	return (fmt);
}
