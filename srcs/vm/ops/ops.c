/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ops.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 10:00:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 13:55:03 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static const t_op_func g_op_funcs[17] =
{
	NULL,
	inst_live,
	inst_ld,
	inst_st,
	inst_add,
	inst_sub,
	inst_and,
	inst_or,
	inst_xor,
	inst_zjmp,
	inst_ldi,
	inst_sti,
	inst_fork,
	inst_lld,
	inst_lldi,
	inst_lfork,
	inst_aff
};

t_op_func	get_op_func(t_inst inst)
{
	if (is_opcode(inst))
		return (g_op_funcs[inst]);
	return (NULL);
};

bool		is_opcode(t_inst inst)
{
	if (inst >= kInstLive && inst <= kInstAff)
		return (true);
	else
		return (false);
}

/*
**	GET_TIMEOUT
**	Get timeout per instruction
*/

int			get_timeout(t_inst inst)
{
	if (is_opcode(inst))
		return (get_opinfo(inst)->timeout);
	else
		return (0);
}
