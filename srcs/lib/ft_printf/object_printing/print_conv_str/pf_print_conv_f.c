/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_print_conv_f.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:33:10 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"
#include "pf_print_num_full.h"

static int		is_negative(t_pf_part *part)
{
	t_pf_f2u	f2u;

	f2u.f = part->value.s_ld_value;
	f2u.ld.s_exp &= 0x000000000000FFFF;
	return (f2u.ld.s_exp & LD_SIGN);
}

static void		print_sign(t_pf_part *part, t_pf_obj *obj)
{
	if (part->flags & PF_SP_FLAG || part->flags & PF_PL_FLAG
		|| is_negative(part))
	{
		if (is_negative(part))
			obj->print("-", 1, obj);
		else
			obj->print((part->flags & PF_PL_FLAG) ? "+" : " ", 1, obj);
	}
}

static t_pf_ret	pf_print_pad_conv_f_blk
	(const char *str, t_pf_part *part, t_pf_obj *obj, t_lenblock lb)
{
	size_t		idx;

	idx = 0;
	while (lb.order[idx] != '\0')
	{
		if (lb.order[idx] == 'S' && *str != '*')
		{
			print_sign(part, obj);
		}
		else if (lb.order[idx] == 'P')
		{
			if (idx == 1 && *str != '*')
				pf_print_nchar('0', lb.pad_len, obj);
			else
				pf_print_nchar(' ', lb.pad_len, obj);
		}
		else if (lb.order[idx] == 'N')
			print_num_full_d(*str == '*' ? str + 1 : str, part->prcs, obj);
		else if (lb.order[idx] == 'D')
			obj->print(".", 1, obj);
		else if (lb.order[idx] == 'p')
			pf_print_nchar('0', part->prcs, obj);
		idx++;
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_print_pad_conv_f
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock	lblock;
	int			needs_dot;

	needs_dot = ((part->flags & PF_HT_FLAG) && ft_strchr(str, '.') == NULL);
	lblock.r_prsc = (int)ft_strlen(*str == '*' ? str + 1 : str);
	lblock.r_width = lblock.r_prsc +
		((part->flags & PF_SP_FLAG || part->flags & PF_PL_FLAG
		|| is_negative(part)) && *str != '*') + needs_dot;
	lblock.total_len =
		(lblock.r_width < part->width) ? part->width : lblock.r_width;
	lblock.pad_len = lblock.total_len - lblock.r_width;
	if (part->flags & PF_MN_FLAG)
		lblock.order = needs_dot ? "SNDP" : "SNP";
	else if (part->flags & PF_ZR_FLAG)
		lblock.order = needs_dot ? "SPND" : "SPN";
	else
		lblock.order = needs_dot ? "PSND" : "PSN";
	pf_print_pad_conv_f_blk(str, part, obj, lblock);
	return (PF_RET_SUCCESS);
}
