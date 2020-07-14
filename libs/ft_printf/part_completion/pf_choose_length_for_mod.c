/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_choose_length_for_mod.c                        :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
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
	if (DECI_CONV & *conv)
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
	else if (STR_CONV & *conv)
		return (get_default_length(conv));
	else if (*conv == F_CONV)
	{
		if (*lenmod & XL_PF_LEN_MOD)
			return (XL_PF_LEN_MOD);
		else if (*lenmod & L_PF_LEN_MOD)
			return (L_PF_LEN_MOD);
		else
			return (get_default_length(conv));
	}
	return (*lenmod);
}
