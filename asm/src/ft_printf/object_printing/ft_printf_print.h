/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print.h                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_PRINT_H
# define FT_PRINTF_PRINT_H

# include "ft_printf_types.h"

typedef t_pf_ret		(*t_pprint_function)(t_pf_obj *, t_pf_part *);

t_pf_ret	ft_print_object(t_pf_obj *obj);
t_pf_ret	ft_printf_print_part_x(t_pf_obj *obj, t_pf_part *part);
t_pf_ret	ft_printf_print_part_u(t_pf_obj *obj, t_pf_part *part);
t_pf_ret	ft_printf_print_part_s(t_pf_obj *obj, t_pf_part *part);
t_pf_ret	ft_printf_print_part_p(t_pf_obj *obj, t_pf_part *part);
t_pf_ret	ft_printf_print_part_o(t_pf_obj *obj, t_pf_part *part);
t_pf_ret	ft_printf_print_part_i(t_pf_obj *obj, t_pf_part *part);
t_pf_ret	ft_printf_print_part_d(t_pf_obj *obj, t_pf_part *part);
t_pf_ret	ft_printf_print_part_c(t_pf_obj *obj, t_pf_part *part);
t_pf_ret	ft_printf_print_part_b(t_pf_obj *obj, t_pf_part *part);
t_pf_ret	ft_printf_print_part_f(t_pf_obj *obj, t_pf_part *part);

#endif
