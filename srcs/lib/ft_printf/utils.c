/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <marvin@42.fr>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 00:08:47 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:34:58 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#ifdef __linux__

int			get_fd(t_pf_obj *obj)
{
	return (obj->dest.file->_fileno);
}

#elif __APPLE__

int			get_fd(t_pf_obj *obj)
{
	return (obj->dest.file->_file);
}

#endif

t_pf_ret	empty_part(t_pf_part *part)
{
	part->prcs = PRCS_NS;
	part->width = WIDTH_NS;
	part->conv = CONV_NS;
	part->len_mod = LEN_MOD_NS;
	part->flags = 0;
	return (PF_RET_SUCCESS);
}
