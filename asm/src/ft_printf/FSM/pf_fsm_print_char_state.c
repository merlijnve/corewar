/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm_print_char_state.c                         :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:09 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_fsm.h"

/*
** Rules
** 1: Calls init when: *[(%)]
** 2: Calls end when: *[nul]
** 3: Calls itself when: *[!(%) && !nul] | thus when no other option
*/

t_pf_ret		pf_fsm_print_char_state(t_pf_obj *obj)
{
	t_pf_ret	rc;
	ptrdiff_t	diff;
	char		*adr;

	rc = PF_RET_SUCCESS;
	if (*(obj->input) != '%' && *(obj->input) != '\0' && rc >= 0)
	{
		adr = ft_strchr(obj->input, '%');
		if (adr == NULL)
			adr = ft_strchr(obj->input, '\0');
		diff = adr - obj->input;
		rc = obj->print(obj->input, diff, obj);
		(obj->input) += diff;
	}
	if (rc < 0)
		return (rc);
	if (*(obj->input) == '\0')
		return (PF_RET_END_STATE);
	else
		return (PF_RET_START_STATE);
}
