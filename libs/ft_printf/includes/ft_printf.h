/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/08/19 18:19:19 by jboer         #+#    #+#                 */
/*   Updated: 2020/06/29 16:19:33 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../../libft/libft.h"
# include <stdarg.h>

# define _JOY_ "\U0001F602"
# define _EGGPLANT_ "\U0001F346"
# define _AVOCADO_ "\U0001F951"
# define _OK_ "\U0001F44C"
# define _100_ "\U0001F4AF"
# define _MONKEY_ "\U0001F435"
# define _ALARM_ "\U0001F6A8"

/*
**	SPEC
**	0	NULL
**	1	hh		CHAR
**	2	h		SHORT
**	3	l		LONG
**	4	ll		LONG LONG
**	5	L		LONG DOUBLE
*/

/*
** FLAGS
** [0]	HASH
** [1]	ZERO
** [2]	PLUS
** [3]	MINUS
** [4]	SPACE
*/

/*
**	FID
**	saved as ascii value
*/

typedef struct		s_print
{
	int				flags[5];
	int				width;
	int				prec;
	char			fid;
	int				spec;
	int				check;
	long long		value;
	size_t			printed;
	struct s_print	*next;
}					t_print;

int					ft_printf(const char *fmt, ...);
void				fmtstr_loop(t_print *print, char *fmt, va_list ap);
void				get_va_chr(t_print *print, va_list ap);
void				fmtflow(t_print *print, char *fmt, va_list ap);
int					print_string(t_print *print, char *fmt, va_list ap);
char				*fill_struct(t_print *print, char *fmt, va_list ap);
void				get_va_int(t_print *print, va_list ap);
char				*ft_lltoa(long long n);
int					get_va_str(t_print *print, va_list ap);
void				get_va_ptr(t_print *print, va_list ap);
char				*add_flags(char *str, t_print *print);
char				*fill_width(char *str, t_print *print);
void				get_va_base(t_print *print, va_list ap);
char				*make_width_base(t_print *print, int base, char *str);
void				get_va_uns(t_print *print, va_list ap);
void				print_perc(t_print *print);
void				get_va_flt(t_print *print, va_list ap);
void				get_va_binary(t_print *print, va_list ap);
void				get_va_array(t_print *print, va_list ap);

#endif
