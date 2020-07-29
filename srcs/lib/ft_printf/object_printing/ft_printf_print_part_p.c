/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_print_part_p.c                          :+:       :+:          */
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

t_pf_ret		ft_printf_print_part_p(t_pf_obj *obj, t_pf_part *part)
{
	char *number;

	number = ft_utoa_base((unsigned long long)part->value.ptr, 16);
	if (number == NULL)
		return (PF_RET_ERROR);
	if (part->flags & PF_MN_FLAG && part->flags & PF_ZR_FLAG)
		part->flags &= ~(PF_ZR_FLAG);
	ft_strlower(number);
	part->flags |= PF_HT_FLAG;
	pf_print_pad_conv_p(number, part, obj);
	free(number);
	return (PF_RET_SUCCESS);
}
