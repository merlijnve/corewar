/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_print_conv_u.c                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/31 18:10:24 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/31 18:10:24 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"
#include "pf_print_num_full.h"

static t_pf_ret	pf_print_pad_conv_u_blk
	(const char *str, t_pf_obj *obj, t_lenblock lb)
{
	size_t	idx;

	idx = 0;
	while (lb.order[idx] != '\0')
	{
		if (lb.order[idx] == 'P')
		{
			if (idx == 1)
				pf_print_nchar('0', lb.pad_len, obj);
			else
				pf_print_nchar(' ', lb.pad_len, obj);
		}
		else if (lb.order[idx] == 'N')
			print_num_full_d(str, lb.r_prsc, obj);
		idx++;
	}
	return (PF_RET_SUCCESS);
}

/*
** the - in lb.order does nothing, but makes sure the right pad char is used
*/

t_pf_ret		pf_print_pad_conv_u
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock lb;

	if (part->prcs == 0 && part->value.s_ll_value == 0)
		str = "";
	lb.r_prsc = (int)ft_strlen(str);
	lb.r_prsc = (part->prcs > lb.r_prsc) ? part->prcs : lb.r_prsc;
	lb.r_width = lb.r_prsc +
		(part->flags & PF_SP_FLAG || part->flags & PF_PL_FLAG);
	lb.total_len =
		(lb.r_width < part->width) ? part->width : lb.r_width;
	lb.pad_len = lb.total_len - lb.r_width;
	if (part->flags & PF_MN_FLAG)
		lb.order = "-NP";
	else if (part->prcs != PRCS_NS)
		lb.order = "P-N";
	else if (part->flags & PF_ZR_FLAG)
		lb.order = "-PN";
	else
		lb.order = "P-N";
	pf_print_pad_conv_u_blk(str, obj, lb);
	return (PF_RET_SUCCESS);
}
