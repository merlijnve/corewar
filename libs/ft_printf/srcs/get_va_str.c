/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_str.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/05 19:02:30 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/05/22 14:17:17 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Adds width / checks LJ for left-justify
**	LJ == 1, do left justify
*/

static char	*make_str_wid(int w, char *s, int lj)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(s);
	res = ft_strnew(w);
	while (i < w)
	{
		res[i] = ' ';
		i++;
	}
	if (res == NULL)
		exit(1);
	if (lj == 1)
		ft_strncpy(res, s, len);
	else
		ft_strncpy(&res[w - len], s, len);
	return (res);
}

static char	*str_precision(char *s, int pr)
{
	char	*res;

	res = ft_strnew(pr);
	ft_strncpy(res, s, pr);
	return (res);
}

int			get_va_str(t_print *print, va_list ap)
{
	char	*s;
	char	*res;

	s = va_arg(ap, char *);
	if (s == NULL)
	{
		ft_putstr("(null)");
		print->printed = 6;
		return (0);
	}
	if (print->prec >= 0)
		s = str_precision(s, print->prec);
	if (print->width > (int)ft_strlen(s))
	{
		res = make_str_wid(print->width, s, print->flags[3]);
		ft_putstr(res);
		print->printed = ft_strlen(res);
		ft_strdel(&res);
	}
	else
	{
		ft_putstr(s);
		print->printed = ft_strlen(s);
	}
	return (0);
}
