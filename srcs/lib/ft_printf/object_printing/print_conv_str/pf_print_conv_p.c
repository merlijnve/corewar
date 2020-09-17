/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_print_conv_p.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:33:17 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"
#include "pf_print_num_full.h"

static t_pf_ret	pf_print_pad_conv_p_blk(
	const char *str, t_pf_part *part, t_pf_obj *obj, t_lenblock lb)
{
	int		has_prefix;
	size_t	idx;

	idx = 0;
	has_prefix = (part->flags & PF_HT_FLAG);
	while (lb.order[idx] != '\0')
	{
		if (lb.order[idx] == 'X')
		{
			obj->print("0x", LEN_NS, obj);
		}
		else if (lb.order[idx] == 'P' && has_prefix)
		{
			if (part->flags & PF_ZR_FLAG && part->prcs == PRCS_NS)
				pf_print_nchar('0', lb.pad_len, obj);
			else
				pf_print_nchar(' ', lb.pad_len, obj);
		}
		else if (lb.order[idx] == 'N')
			print_num_full_d(
				str, (has_prefix) ? lb.r_prsc - 2 : lb.r_prsc, obj);
		idx++;
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_p
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock	lb;
	size_t		len;

	if (part->prcs == 0 && part->value.s_ll_value == 0)
		str = "";
	len = ft_strlen(str);
	lb.r_prsc = (int)len + 2;
	lb.r_prsc = (part->prcs + 2 > lb.r_prsc) ? part->prcs + 2 : lb.r_prsc;
	lb.r_width = lb.r_prsc;
	lb.total_len = (lb.r_width < part->width) ? part->width : lb.r_width;
	lb.pad_len = lb.total_len - lb.r_width;
	if (part->flags & PF_MN_FLAG)
		lb.order = "XNP";
	else
		lb.order = "PXN";
	pf_print_pad_conv_p_blk(str, part, obj, lb);
	return (PF_RET_SUCCESS);
}
