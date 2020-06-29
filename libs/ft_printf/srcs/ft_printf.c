/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:08:46 by jboer         #+#    #+#                 */
/*   Updated: 2020/05/22 14:16:13 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	free_struct(t_print *print)
{
	t_print *temp;
	size_t	printed_chars;

	printed_chars = 0;
	while (print)
	{
		printed_chars += print->printed;
		temp = print;
		print = print->next;
		ft_memdel((void **)&temp);
	}
	ft_memdel((void **)print);
	return (printed_chars);
}

int			ft_printf(const char *fmt, ...)
{
	va_list	ap;
	t_print	*print;
	char	*dup;
	int		printed_chars;

	va_start(ap, fmt);
	print = (t_print *)ft_memalloc(sizeof(t_print));
	if (!print)
		exit(1);
	print->next = NULL;
	dup = (char *)fmt;
	fmtflow(print, dup, ap);
	printed_chars = print_string(print, dup, ap);
	printed_chars += free_struct(print);
	va_end(ap);
	return (printed_chars);
}
