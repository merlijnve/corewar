/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_fsm_flags_state.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:30:47 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_fsm.h"

static t_pf_ret	set_flag(const char c, t_pf_obj *obj)
{
	if (c == '0')
		obj->part->flags |= PF_ZR_FLAG;
	else if (c == ' ')
		obj->part->flags |= PF_SP_FLAG;
	else if (c == '#')
		obj->part->flags |= PF_HT_FLAG;
	else if (c == '+')
		obj->part->flags |= PF_PL_FLAG;
	else if (c == '-')
		obj->part->flags |= PF_MN_FLAG;
	else if (c == '\'')
		obj->part->flags |= PF_AP_FLAG;
	else
		return (PF_RET_FORMAT_ERROR);
	return (PF_RET_SUCCESS);
}

t_pf_ret		pf_fsm_flags_state(t_pf_obj *obj)
{
	t_pf_ret	rc;

	if (ft_memchr(FLAG_OPTS, *(obj->input), L_FLAG_OPTS) != NULL)
		rc = set_flag(*(obj->input), obj);
	else
		return (PF_RET_ERROR_STATE);
	if (rc < 0)
		return (PF_RET_ERROR_STATE);
	(obj->input)++;
	if (ft_memchr(CONV_OPTS, *(obj->input), L_CONV_OPTS) != NULL)
		return (PF_RET_CONV_STATE);
	else if (ft_memchr(WIDTH_OPTS, *(obj->input), L_WIDTH_OPTS))
		return (PF_RET_WIDTH_STATE);
	else if (ft_memchr(FLAG_OPTS, *(obj->input), L_FLAG_OPTS) != NULL)
		return (PF_RET_FLAGS_STATE);
	else if (ft_memchr(PRECIS_OPTS, *(obj->input), L_PRECIS_OPTS))
		return (PF_RET_PRECIS_STATE);
	else if (ft_memchr(LENG_OPTS, *(obj->input), L_LENG_OPTS))
		return (PF_RET_LENGTH_STATE);
	else if (ft_memchr(WILDCARD_OPTS, *(obj->input), L_WILDCARD_OPTS))
		return (PF_RET_WILDCARD_WIDTH_STATE);
	else
		return (PF_RET_PRINT_EMPTY_OBJECT_STATE);
	return (PF_RET_ERROR_STATE);
}
