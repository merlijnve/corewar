/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_fsm_controller_state.c                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:30:27 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pf_fsm.h"

static t_state_function	g_jump_table[14] =
{
	pf_fsm_conv_state,
	pf_fsm_end_state,
	pf_fsm_error_state,
	pf_fsm_flags_state,
	pf_fsm_length_state,
	pf_fsm_precis_state,
	pf_fsm_width_state,
	pf_fsm_start_state,
	pf_fsm_print_object_state,
	pf_fsm_print_empty_object_state,
	pf_fsm_print_char_state,
	pf_fsm_init_state,
	pf_fsm_wildcard_prcs_state,
	pf_fsm_wildcard_width_state,
};

t_pf_ret				pf_fsm_controller_state(t_pf_obj *obj)
{
	t_pf_ret ret;

	ret = PF_RET_START_STATE;
	while (ret >= 10 && ret <= 23)
	{
		ret = g_jump_table[ret - 10](obj);
		if (ret == PF_RET_SUCCESS && *(obj->input) != '\0')
			ret = PF_RET_START_STATE;
	}
	obj->print(NULL, 0, obj);
	return (ret);
}
