/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_chr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/30 14:45:26 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/05/22 14:16:31 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Adds width / checks LJ for left-justify
**	LJ == 1, do left justify
*/

static char	*make_chr_wid(int w, char c, int lj)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(w);
	if (res == NULL)
		exit(1);
	ft_memset(res, ' ', w);
	if (lj == 1)
		res[0] = c;
	else
		res[w - 1] = c;
	return (res);
}

void		get_va_chr(t_print *print, va_list ap)
{
	char	c;
	char	*s;
	int		i;

	i = 0;
	c = (char)va_arg(ap, int);
	if (print->width > 1)
	{
		s = make_chr_wid(print->width, c, print->flags[3]);
		print->printed = print->width;
		while (i < print->width)
		{
			ft_putchar(s[i]);
			i++;
		}
		ft_strdel(&s);
	}
	else
	{
		ft_putchar(c);
		print->printed = 1;
	}
}
