/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 00:08:47 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/07/31 15:52:52 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_pf_ret	empty_part(t_pf_part *part)
{
	part->prcs = PRCS_NS;
	part->width = WIDTH_NS;
	part->conv = CONV_NS;
	part->len_mod = LEN_MOD_NS;
	part->flags = 0;
	return (PF_RET_SUCCESS);
}
