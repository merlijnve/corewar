/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_print_functions.h                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINT_FUNCTIONS_H
# define FT_PRINT_FUNCTIONS_H

# include <string.h>
# include "ft_printf_types.h"

t_pf_ret	print(const char *str, ssize_t n, t_pf_obj *obj);

#endif
