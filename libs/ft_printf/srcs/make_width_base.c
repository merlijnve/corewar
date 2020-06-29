/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_width_base.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/13 11:00:28 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/05/22 14:17:26 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char		*place_prepos_mid(t_print *print, int rest, char *str, char *t)
{
	char	*temp;
	int		len;

	len = ft_strlen(str);
	temp = t;
	if (print->flags[3] == 1)
		t = ft_strncpy(&t[rest], str, len);
	else
		t = ft_strncpy(&t[print->width - len], str, len);
	if (print->value != 0)
	{
		if (rest == 1)
			temp[print->width - len - 1] = '0';
		else
			ft_strncpy(&temp[print->width - len - 2], "0x", 2);
	}
	return (temp);
}

static char		*place_prepos(t_print *print, int rest, char *str, char *t)
{
	int		len;

	len = ft_strlen(str);
	if (print->flags[3] == 1)
	{
		ft_strncpy(&t[rest], str, len);
		if (rest == 1)
			t[0] = '0';
		else
			ft_strncpy(t, "0x", 2);
	}
	else
		t = place_prepos_mid(print, rest, str, t);
	return (t);
}

static char		*make_width_hash(t_print *print, int rest, char *str)
{
	char	*t;
	int		len;
	char	*temp;

	len = ft_strlen(str);
	t = ft_strnew(print->width);
	temp = t;
	ft_memset((void *)t, ' ', print->width);
	if (print->flags[1] == 1 && print->flags[3] != 1)
		ft_memset((void *)t, '0', print->width);
	if (print->flags[0] && print->flags[1] && rest == 2 && !print->flags[3])
	{
		ft_strncpy(&t[print->width - len], str, len);
		ft_strncpy(t, "0x", 2);
	}
	else
		place_prepos(print, rest, str, temp);
	ft_strdel(&str);
	return (temp);
}

static char		*make_width_norm(t_print *print, char *str)
{
	char	*t;
	char	*temp;
	int		len;

	len = ft_strlen(str);
	t = ft_strnew(print->width);
	temp = t;
	ft_memset((void *)t, ' ', print->width);
	if (print->flags[1] == 1 && print->flags[3] != 1)
		ft_memset((void *)t, '0', print->width);
	if (print->flags[3] == 1)
		t = ft_strncpy(t, str, len);
	else
		t = ft_strncpy(&t[print->width - len], str, len);
	ft_strdel(&str);
	return (temp);
}

char			*make_width_base(t_print *print, int base, char *str)
{
	int		rest;
	int		len;

	len = (int)ft_strlen(str);
	rest = 0;
	if (print->flags[0] == 1)
		rest = base / 8;
	if (print->flags[0] == 1 && print->width - rest > len)
		str = make_width_hash(print, rest, str);
	else
		str = make_width_norm(print, str);
	if (print->value == 0 && print->prec == 0)
		ft_memset(str, ' ', print->width);
	return (str);
}
