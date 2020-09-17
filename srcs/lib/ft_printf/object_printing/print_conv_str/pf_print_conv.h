/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_print_conv.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:33:35 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_PRINT_CONV_H
# define PF_PRINT_CONV_H

# include "ft_printf_types.h"

t_pf_ret	pf_print_pad_conv_o
	(const char *str, t_pf_part *part, t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_x
	(const char *str, t_pf_part *part, t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_u
	(const char *str, t_pf_part *part, t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_d
	(const char *str, t_pf_part *part, t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_c
	(const char *str, t_pf_part *part, t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_s
	(const char *str, t_pf_part *part, t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_p
	(const char *str, t_pf_part *part, t_pf_obj *obj);
t_pf_ret	pf_print_pad_conv_f
	(const char *str, t_pf_part *part, t_pf_obj *obj);

#endif
