/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_choose_length_for_mod.h                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:34:33 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_CHOOSE_LENGTH_FOR_MOD_H
# define PF_CHOOSE_LENGTH_FOR_MOD_H

# include "ft_printf_types.h"

t_pf_len_mod pf_get_length_for_conv(t_pf_len_mod *lenmod, t_pf_conv *conv);

#endif
