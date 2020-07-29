/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_print_empty_object_state.c                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_print.h"
#include "pf_fsm.h"

static t_pf_ret
	set_part(t_pf_obj *obj)
{
	t_pf_part *part;

	part = obj->part;
	part->conv = C_CONV;
	part->value.s_it_value = (int)*(obj->input);
	return (PF_RET_SUCCESS);
}

/*
** still have to manage some stuff.. (later me: ehm but what?)
** later not you, moved this comment here and put this in TODO.
*/

t_pf_ret
	pf_fsm_print_empty_object_state(t_pf_obj *obj)
{
	if (*(obj->input) != '\0')
	{
		set_part(obj);
		ft_print_object(obj);
		(obj->input)++;
	}
	return (PF_RET_END_STATE);
}
