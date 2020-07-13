/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf.h                                       :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:44 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:00 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>

int ft_printf(const char *format, ...);
int ft_fprintf(FILE *stream, const char *format, ...);
int ft_dprintf(int fd, const char *format, ...);

int ft_vprintf(const char *format, va_list ap);
int ft_vfprintf(FILE *stream, const char *format, va_list ap);
int ft_vdprintf(int fd, const char *format, va_list ap);

#endif
