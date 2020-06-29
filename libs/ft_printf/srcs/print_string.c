/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/22 16:21:57 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/05/22 14:17:34 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	print_arg(t_print *print, va_list ap)
{
	if (print->fid == 'd' || print->fid == 'i')
		get_va_int(print, ap);
	if (print->fid == 'o' || print->fid == 'x' || print->fid == 'X')
		get_va_base(print, ap);
	if (print->fid == 'u')
		get_va_uns(print, ap);
	if (print->fid == 'f')
		get_va_flt(print, ap);
	if (print->fid == 'c')
		get_va_chr(print, ap);
	if (print->fid == 'p')
		get_va_ptr(print, ap);
	if (print->fid == 's')
		get_va_str(print, ap);
	if (print->fid == '%')
		print_perc(print);
	if (print->fid == 'b')
		get_va_binary(print, ap);
	if (print->fid == 'a')
		get_va_array(print, ap);
}

int		print_chars(char *fmt)
{
	int	printed_chars;

	printed_chars = 0;
	while (*fmt && *fmt != '%')
	{
		ft_putchar(*fmt);
		printed_chars += 1;
		fmt++;
	}
	return (printed_chars);
}

char	*skip_chars(char *fmt)
{
	while (*fmt && *fmt != 'd' && *fmt != 'i' && *fmt != 'o' && *fmt != 'x'
	&& *fmt != 'u' && *fmt != 'X' && *fmt != 's' && *fmt != 'c'
	&& *fmt != 'p' && *fmt != 'f' && *fmt != '%' && *fmt != 'b'
	&& *fmt != 'a')
		fmt++;
	return (fmt);
}

int		print_string(t_print *print, char *fmt, va_list ap)
{
	int	printed_chars;
	int	t;

	printed_chars = 0;
	while (*fmt)
	{
		t = print_chars(fmt);
		fmt += t;
		printed_chars += t;
		if (!*fmt)
			return (printed_chars);
		print_arg(print, ap);
		if (!print)
			return (0);
		print = print->next;
		fmt++;
		fmt = skip_chars(fmt);
		if (!*fmt)
			return (printed_chars);
		fmt++;
	}
	return (printed_chars);
}
