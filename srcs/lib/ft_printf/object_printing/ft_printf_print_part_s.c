/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_part_s.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:34:04 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print.h"
#include "pf_print_conv.h"

t_pf_ret	ft_printf_print_part_s(t_pf_obj *obj, t_pf_part *part)
{
	if (part->value.s_ch_ptr_value == NULL)
		part->value.s_ch_ptr_value = "(null)";
	if (part->flags & PF_MN_FLAG && part->flags & PF_ZR_FLAG)
		part->flags &= ~(PF_ZR_FLAG);
	pf_print_pad_conv_s(part->value.s_ch_ptr_value, part, obj);
	return (PF_RET_SUCCESS);
}
