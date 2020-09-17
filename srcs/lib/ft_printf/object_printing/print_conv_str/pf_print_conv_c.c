/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_print_conv_c.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:33:04 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"

static t_pf_ret	pf_print_pad_conv_c_blk
	(const char *str, t_pf_part *part, t_pf_obj *obj, t_lenblock lb)
{
	size_t	idx;

	idx = 0;
	while (lb.order[idx] != '\0')
	{
		if (lb.order[idx] == 'N')
			obj->print(str, 1, obj);
		else if (lb.order[idx] == 'P')
		{
			if (part->flags & PF_ZR_FLAG)
				pf_print_nchar('0', lb.pad_len, obj);
			else
				pf_print_nchar(' ', lb.pad_len, obj);
		}
		idx++;
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_c
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock lblock;

	lblock.r_prsc = (part->prcs > 1) ? part->prcs : 1;
	lblock.r_width = lblock.r_prsc;
	lblock.total_len =
		(lblock.r_width < part->width) ? part->width : lblock.r_width;
	lblock.pad_len = lblock.total_len - lblock.r_width;
	if (part->flags & PF_MN_FLAG)
		lblock.order = "NP";
	else
		lblock.order = "PN";
	pf_print_pad_conv_c_blk(str, part, obj, lblock);
	return (PF_RET_SUCCESS);
}
