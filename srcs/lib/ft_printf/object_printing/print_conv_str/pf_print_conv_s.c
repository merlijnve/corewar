/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_print_conv_s.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/16 22:01:07 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:33:19 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"

static t_pf_ret	pf_print_pad_conv_s_blk
	(const char *str, t_pf_obj *obj, t_lenblock lb)
{
	size_t	idx;

	idx = 0;
	while (lb.order[idx] != '\0')
	{
		if (lb.order[idx] == 'N')
			obj->print(str, lb.r_prsc, obj);
		else if (lb.order[idx] == 'P')
		{
			if (obj->part->flags & PF_ZR_FLAG)
				pf_print_nchar('0', lb.pad_len, obj);
			else
				pf_print_nchar(' ', lb.pad_len, obj);
		}
		idx++;
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_s
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock	lblock;
	int			len;

	len = (int)ft_strlen(str);
	if (part->prcs == PRCS_NS)
		lblock.r_prsc = len;
	else
		lblock.r_prsc = part->prcs;
	lblock.r_prsc = (len < lblock.r_prsc ? len : lblock.r_prsc);
	if (part->width == WIDTH_NS)
		lblock.pad_len = 0;
	else
		lblock.pad_len =
		(part->width - lblock.r_prsc) > 0 ? (part->width - lblock.r_prsc) : 0;
	if (part->flags & PF_MN_FLAG)
		lblock.order = "SNP";
	else
		lblock.order = "SPN";
	pf_print_pad_conv_s_blk(str, obj, lblock);
	return (PF_RET_SUCCESS);
}
