/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_print_functions.h                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:34:44 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_FUNCTIONS_H
# define FT_PRINT_FUNCTIONS_H

# include <string.h>
# include "ft_printf_types.h"

t_pf_ret	print(const char *str, ssize_t n, t_pf_obj *obj);

#endif
