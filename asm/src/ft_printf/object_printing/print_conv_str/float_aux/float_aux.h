/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_aux.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 19:29:23 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/12/01 19:29:24 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOAT_AUX_H
# define FLOAT_AUX_H

# include "ft_printf_types.h"

char	*str_add(char *dst, char *src, size_t n);
char	*str_add_rightside(char *dst, char *src, size_t n);
char	*str_round(char *str, int prcs);
char	*set_left_of_dot(char *str, int d_exp, t_ld_parts ld, unsigned long *i);
char	*set_right_of_dot(char *str, int prcs, t_ld_parts ld, unsigned long i);
char	*ft_ftoa(t_pf_part *part);

#endif
