/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_c.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print.h"
#include "pf_print_conv.h"

t_pf_ret	ft_printf_print_part_c(t_pf_obj *obj, t_pf_part *part)
{
	char str[2];

	if (part->flags & PF_MN_FLAG && part->flags & PF_ZR_FLAG)
		part->flags &= ~PF_ZR_FLAG;
	str[0] = part->value.u_ch_value;
	str[1] = '\0';
	pf_print_pad_conv_c(str, part, obj);
	return (PF_RET_SUCCESS);
}
