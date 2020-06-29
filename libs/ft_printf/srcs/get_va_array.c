/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_va_array.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/28 16:40:51 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/05/22 14:16:16 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
**	Prints out (2d) arrays
**	Needs amount of rows and defaults to 1
*/

static void	print_row(int *row, unsigned int columns, t_print *print)
{
	unsigned int	i;
	char			spaces[50];
	int				c;

	c = print->flags[1] ? '0' : ' ';
	i = 0;
	while (i < 50)
	{
		spaces[i] = c;
		i++;
	}
	spaces[49] = '\0';
	i = 0;
	while (i < columns)
	{
		ft_putchar('[');
		if (print->width > ft_digitc(row[i]))
			ft_putstr(&spaces[50 + ft_digitc(row[i]) - print->width]);
		ft_putnbr(row[i]);
		ft_putchar(']');
		i++;
	}
}

static void	print_char_row(char *str, t_print *print, int c)
{
	char	spaces[200];
	int		i;

	c = print->flags[1] ? '0' : ' ';
	i = 0;
	while (i < 200)
	{
		spaces[i] = c;
		i++;
	}
	spaces[199] = '\0';
	i = 0;
	if (print->flags[3])
	{
		ft_putstr(str);
		if (print->width > (int)ft_strlen(str))
			ft_putstr(&spaces[200 + ft_strlen(str) - print->width]);
		ft_putchar('\n');
	}
	else
	{
		if (print->width > (int)ft_strlen(str))
			ft_putstr(&spaces[200 + ft_strlen(str) - print->width]);
		ft_putendl(str);
	}
}

static void	get_va_int_array(t_print *print, va_list ap)
{
	int				**ar;
	unsigned int	i;
	unsigned int	columns;
	unsigned int	rows;

	i = 0;
	ar = va_arg(ap, int **);
	columns = va_arg(ap, unsigned int);
	rows = va_arg(ap, unsigned int);
	while (i < rows)
	{
		print_row(ar[i], columns, print);
		ft_putchar('\n');
		i++;
	}
}

static void	get_va_char_array(t_print *print, va_list ap)
{
	char			**ar;
	unsigned int	rows;
	unsigned int	i;
	int				c;

	c = 0;
	i = 0;
	ar = va_arg(ap, char **);
	rows = va_arg(ap, unsigned int);
	while (i < rows)
	{
		print_char_row(ar[i], print, c);
		i++;
	}
}

void		get_va_array(t_print *print, va_list ap)
{
	if (print->flags[0])
		get_va_int_array(print, ap);
	else
		get_va_char_array(print, ap);
}
