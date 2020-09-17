/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_print_conv_o.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:46:02 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:33:13 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "pf_print_conv.h"
#include "pf_print_nchar.h"
#include "pf_print_num_full.h"

static t_pf_ret	pf_print_pad_conv_o_blk
	(const char *str, t_pf_part *part, t_pf_obj *obj, t_lenblock lb)
{
	size_t	idx;

	idx = 0;
	while (lb.order[idx] != '\0')
	{
		if (lb.order[idx] == 'P')
		{
			if (part->flags & PF_ZR_FLAG && part->prcs == PRCS_NS)
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

t_pf_ret		pf_print_pad_conv_o
	(const char *str, t_pf_part *part, t_pf_obj *obj)
{
	t_lenblock	lb;
	char		*str_new;

	str_new = NULL;
	if (part->prcs == 0 && part->value.s_ll_value == 0)
		str = "";
	if (part->flags & PF_HT_FLAG && *str != '0')
	{
		str_new = ft_strnew(ft_strlen(str) + 1);
		*str_new = '0';
		ft_strcat(str_new, str);
		str = str_new;
	}
	lb.r_prsc = (int)ft_strlen(str);
	lb.r_prsc = (part->prcs > lb.r_prsc) ? part->prcs : lb.r_prsc;
	lb.r_width = lb.r_prsc;
	lb.total_len = (lb.r_width < part->width) ? part->width : lb.r_width;
	lb.pad_len = lb.total_len - lb.r_width;
	if (part->flags & PF_MN_FLAG)
		lb.order = "NP";
	else
		lb.order = "PN";
	pf_print_pad_conv_o_blk(str, part, obj, lb);
	free(str_new);
	return (PF_RET_SUCCESS);
}
