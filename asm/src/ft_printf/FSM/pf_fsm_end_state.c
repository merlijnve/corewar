/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_end_state.c                                :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "pf_fsm.h"

/*
** this function needs to be expanded the if statement is there to
** make the code compile without a warning for unused parameters
*/

t_pf_ret	pf_fsm_end_state(t_pf_obj *obj)
{
	if (obj)
		return (PF_RET_SUCCESS);
	return (PF_RET_SUCCESS);
}
