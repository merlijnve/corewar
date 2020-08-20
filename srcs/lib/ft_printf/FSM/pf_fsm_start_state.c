/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_start_state.c                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "pf_fsm.h"

t_pf_ret	pf_fsm_start_state(t_pf_obj *obj)
{
	if (*(obj->input) == '%')
		return (PF_RET_INIT_STATE);
	else if (*(obj->input) != '\0' && *(obj->input) != '%')
		return (PF_RET_PRINT_CHAR_STATE);
	if (*(obj->input) == '\0')
		return (PF_RET_END_STATE);
	else
		return (PF_RET_HAS_MORE);
}
