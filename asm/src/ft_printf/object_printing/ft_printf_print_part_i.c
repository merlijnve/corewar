/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_i.c                          :+:       :+:          */
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

t_pf_ret	ft_printf_print_part_i(t_pf_obj *obj, t_pf_part *part)
{
	char *number;

	number = ft_itoa_base(part->value.s_ll_value, 10);
	if (number == NULL)
		return (PF_RET_ERROR);
	if (part->flags & PF_MN_FLAG && part->flags & PF_ZR_FLAG)
		part->flags &= ~(PF_ZR_FLAG);
	pf_print_pad_conv_d(*number == '-' ? number + 1 : number, part, obj);
	free(number);
	return (PF_RET_SUCCESS);
}
