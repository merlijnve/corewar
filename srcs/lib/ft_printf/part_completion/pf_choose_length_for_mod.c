/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_choose_length_for_mod.c                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:34:36 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_choose_length_for_mod.h"

static t_pf_len_mod	get_default_length(t_pf_conv *conv)
{
	if (*conv == D_CONV)
		return (L_PF_LEN_MOD);
	else if (*conv == I_CONV)
		return (L_PF_LEN_MOD);
	else if (*conv == O_CONV)
		return (L_PF_LEN_MOD);
	else if (*conv == U_CONV)
		return (L_PF_LEN_MOD);
	else if (*conv == X_CONV)
		return (L_PF_LEN_MOD);
	else if (*conv == XX_CONV)
		return (L_PF_LEN_MOD);
	else if (*conv == F_CONV)
		return (L_PF_LEN_MOD);
	else if (*conv == C_CONV)
		return (HH_PF_LEN_MOD);
	else if (*conv == S_CONV)
		return (HH_PF_LEN_MOD);
	else if (*conv == P_CONV)
		return (L_PF_LEN_MOD);
	else
		return (L_PF_LEN_MOD);
}

t_pf_len_mod		pf_get_length_for_conv
	(t_pf_len_mod *lenmod, t_pf_conv *conv)
{
	if ((D_CONV | I_CONV | O_CONV | U_CONV | B_CONV |
			XX_CONV | XD_CONV | XO_CONV | XU_CONV | X_CONV) & *conv)
	{
		if (*lenmod & LL_PF_LEN_MOD)
			return (LL_PF_LEN_MOD);
		else if (*lenmod & L_PF_LEN_MOD)
			return (L_PF_LEN_MOD);
		else if (*lenmod & H_PF_LEN_MOD)
			return (H_PF_LEN_MOD);
		else if (*lenmod & HH_PF_LEN_MOD)
			return (HH_PF_LEN_MOD);
		else
			return (get_default_length(conv));
	}
	else if ((C_CONV | S_CONV | P_CONV) & *conv)
		return (get_default_length(conv));
	else if (*conv == F_CONV)
	{
		if (*lenmod & XL_PF_LEN_MOD)
			return (XL_PF_LEN_MOD);
		else if (*lenmod & L_PF_LEN_MOD)
			return (*lenmod & L_PF_LEN_MOD) ?
			(L_PF_LEN_MOD) : get_default_length(conv);
	}
	return (*lenmod);
}
