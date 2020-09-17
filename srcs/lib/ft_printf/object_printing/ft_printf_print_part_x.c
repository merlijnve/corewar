/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_part_x.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:34:11 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "ft_printf_print.h"
#include "pf_print_conv.h"

static t_pf_ret	change_chars(char *str, t_pf_part *part)
{
	if (part->conv == XX_CONV)
		ft_strupper(str);
	else if (part->conv == X_CONV)
		ft_strlower(str);
	return (PF_RET_SUCCESS);
}

t_pf_ret		ft_printf_print_part_x(t_pf_obj *obj, t_pf_part *part)
{
	char *number;

	number = ft_utoa_base(part->value.u_ll_value, 16);
	if (number == NULL)
		return (PF_RET_ERROR);
	if (part->flags & PF_MN_FLAG && part->flags & PF_ZR_FLAG)
		part->flags &= ~(PF_ZR_FLAG);
	change_chars(number, part);
	pf_print_pad_conv_x(number, part, obj);
	free(number);
	return (PF_RET_SUCCESS);
}
