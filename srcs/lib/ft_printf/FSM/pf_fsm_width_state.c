/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_fsm_width_state.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:31:14 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "pf_fsm.h"

static t_pf_ret	set_width(t_pf_obj *obj)
{
	char c;

	c = *(obj->input);
	if (ft_memchr(WIDTH_OPTS, *(obj->input - 1), L_WIDTH_OPTS) == NULL)
		obj->part->width = 0;
	if (ft_memchr(WIDTH_OPTS_X, c, L_WIDTH_OPTS_X))
	{
		if (c >= '0' && c <= '9')
		{
			obj->part->width *= 10;
			obj->part->width += (int)(c - '0');
		}
		else
			return (PF_RET_FORMAT_ERROR);
	}
	else
		return (PF_RET_FORMAT_ERROR);
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_fsm_width_state(t_pf_obj *obj)
{
	t_pf_ret	rc;

	rc = PF_RET_SUCCESS;
	if (ft_memchr(PRECIS_OPTS_X, *(obj->input), L_PRECIS_OPTS_X))
		rc = set_width(obj);
	if (rc < 0)
		return (PF_RET_ERROR_STATE);
	(obj->input)++;
	if (ft_memchr(CONV_OPTS, *(obj->input), L_CONV_OPTS))
		return (PF_RET_CONV_STATE);
	else if (ft_memchr(WIDTH_OPTS_X, *(obj->input), L_WIDTH_OPTS_X))
		return (PF_RET_WIDTH_STATE);
	else if (ft_memchr(FLAG_OPTS, *(obj->input), L_FLAG_OPTS))
		return (PF_RET_FLAGS_STATE);
	else if (ft_memchr(PRECIS_OPTS, *(obj->input), L_PRECIS_OPTS))
		return (PF_RET_PRECIS_STATE);
	else if (ft_memchr(LENG_OPTS, *(obj->input), L_LENG_OPTS))
		return (PF_RET_LENGTH_STATE);
	else if (ft_memchr(WILDCARD_OPTS, *(obj->input), L_WILDCARD_OPTS))
		return (PF_RET_WILDCARD_WIDTH_STATE);
	else
		return (PF_RET_PRINT_EMPTY_OBJECT_STATE);
}
