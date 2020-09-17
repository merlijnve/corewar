/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_fsm_conv_state.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:30:34 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_fsm.h"

static t_pf_conv g_conversion_table[58] =
{
	XA_CONV, XB_CONV, XC_CONV, XD_CONV, XE_CONV, XF_CONV, XG_CONV, XH_CONV,
	XI_CONV, XJ_CONV, XK_CONV, XL_CONV, XM_CONV, XN_CONV, XO_CONV, XP_CONV,
	XQ_CONV, XR_CONV, XS_CONV, XT_CONV, XU_CONV, XV_CONV, XW_CONV, XX_CONV,
	XY_CONV, XZ_CONV,
	NOT_A_CONV, NOT_A_CONV, NOT_A_CONV,
	NOT_A_CONV, NOT_A_CONV, NOT_A_CONV,
	A_CONV, B_CONV, C_CONV, D_CONV, E_CONV, F_CONV, G_CONV, H_CONV,
	I_CONV, J_CONV, K_CONV, L_CONV, M_CONV, N_CONV, O_CONV, P_CONV,
	Q_CONV, R_CONV, S_CONV, T_CONV, U_CONV, V_CONV, W_CONV, X_CONV,
	Y_CONV, Z_CONV,
};

static t_pf_ret	set_conv(const char c, t_pf_obj *obj)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
		obj->part->conv = g_conversion_table[(c - 'A')];
	else
		return (PF_RET_FORMAT_ERROR);
	if (obj->part->conv & (XD_CONV | XO_CONV | XU_CONV))
	{
		obj->part->len_mod = L_PF_LEN_MOD;
	}
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_fsm_conv_state(t_pf_obj *obj)
{
	t_pf_ret	rc;

	rc = PF_RET_PRINT_OBJECT_STATE;
	if (ft_memchr(CONV_OPTS, *(obj->input), L_CONV_OPTS) != NULL)
		rc = set_conv(*(obj->input), obj);
	if (rc < 0)
		return (PF_RET_ERROR_STATE);
	else
		return (PF_RET_PRINT_OBJECT_STATE);
}
