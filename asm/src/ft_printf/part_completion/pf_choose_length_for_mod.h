/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_choose_length_for_mod.h                        :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_CHOOSE_LENGTH_FOR_MOD_H
# define PF_CHOOSE_LENGTH_FOR_MOD_H

# include "ft_printf_types.h"

# define DECI_CONV_EXT (XX_CONV | XD_CONV | XO_CONV | XU_CONV | X_CONV)
# define DECI_CONV (D_CONV | I_CONV | O_CONV | U_CONV | B_CONV | DECI_CONV_EXT)
# define STR_CONV (C_CONV | S_CONV | P_CONV)

/*
** not yet classified
** A_CONV | XA_CONV | E_CONV | XE_CONV | G_CONV | XG_CONV | V_CONV |CONV_NS
*/

# define PNTR_CONV (N_CONV | S_CONV | P_CONV)
# define SIGN_CONV (U_CONV | O_CONV | X_CONV | XX_CONV | B_CONV)
# define FLOAT_CONV (F_CONV | XF_CONV)

/*
** # define NO_PNTR_CONV (D_CONV | I_CONV | O_CONV | U_CONV |
** X_CONV | XX_CONV | F_CONV | XF_CONV | C_CONV | B_CONV)
*/

t_pf_len_mod pf_get_length_for_conv(t_pf_len_mod *lenmod, t_pf_conv *conv);

#endif
