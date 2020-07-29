/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_o.c                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:01 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "ft_printf_print.h"
#include "pf_print_conv.h"

t_pf_ret	ft_printf_print_part_o(t_pf_obj *obj, t_pf_part *part)
{
	char *number;

	number = ft_utoa_base(part->value.u_ll_value, 8);
	if (number == NULL)
		return (PF_RET_ERROR);
	if (part->flags & PF_MN_FLAG && part->flags & PF_ZR_FLAG)
		part->flags &= ~(PF_ZR_FLAG);
	pf_print_pad_conv_o(number, part, obj);
	free(number);
	return (PF_RET_SUCCESS);
}
