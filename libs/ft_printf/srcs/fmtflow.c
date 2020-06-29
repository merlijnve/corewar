/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fmtflow.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/21 15:21:58 by jboer         #+#    #+#                 */
/*   Updated: 2020/05/22 14:16:07 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			fmtflow(t_print *print, char *fmt, va_list ap)
{
	while (ft_strchr(fmt, '%'))
	{
		while (*fmt != '%')
			fmt++;
		fmt = fill_struct(print, fmt, ap);
		if (ft_strchr(fmt, '%'))
		{
			print->next = ft_memalloc(sizeof(t_print));
			if (!print)
				exit(1);
			print = print->next;
			print->next = NULL;
			continue;
		}
		else
			break ;
	}
}
