/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_fsm_error_state.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:30:44 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_fsm.h"

t_pf_ret	pf_fsm_error_state(t_pf_obj *obj)
{
	if (obj)
		ft_putstr(obj->input);
	return (PF_RET_NO_STATE_SET);
}
