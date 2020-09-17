/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_vprintf.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:44 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:34:55 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "utils.h"
#include "ft_printf.h"
#include "ft_print_functions.h"
#include "ft_printf_types.h"
#include "pf_fsm.h"

int		ft_vprintf(const char *format, va_list ap)
{
	va_list		apc;
	t_pf_obj	object;
	t_pf_part	part;

	va_copy(apc, ap);
	empty_part(&part);
	object.part = &part;
	object.print = &print;
	object.chr_wrtn = 0;
	object.args = &apc;
	object.input = format;
	object.dtype = PRINT_DEST_FIDES;
	object.dest.fd = 1;
	pf_fsm_controller_state(&object);
	va_end(apc);
	return ((int)object.chr_wrtn);
}

int		ft_vfprintf(FILE *stream, const char *format, va_list ap)
{
	va_list		apc;
	t_pf_obj	object;
	t_pf_part	part;

	va_copy(apc, ap);
	empty_part(&part);
	object.part = &part;
	object.print = &print;
	object.chr_wrtn = 0;
	object.args = &apc;
	object.input = format;
	object.dtype = PRINT_DEST_STREAM;
	object.dest.file = stream;
	pf_fsm_controller_state(&object);
	va_end(apc);
	return ((int)object.chr_wrtn);
}

int		ft_vdprintf(int fd, const char *format, va_list ap)
{
	va_list		apc;
	t_pf_obj	object;
	t_pf_part	part;

	va_copy(apc, ap);
	empty_part(&part);
	object.part = &part;
	object.print = &print;
	object.chr_wrtn = 0;
	object.args = &apc;
	object.input = format;
	object.dtype = PRINT_DEST_FIDES;
	object.dest.fd = fd;
	pf_fsm_controller_state(&object);
	va_end(apc);
	return ((int)object.chr_wrtn);
}
