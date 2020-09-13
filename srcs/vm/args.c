/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 13:48:52 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/13 14:30:32 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_args_type		get_arg(t_enbyte byte, t_inst inst, int argnr)
{
	if (get_opinfo(inst)->has_enbyte)
	{
		if (argnr == 1)
			return (byte.arg1);
		if (argnr == 2)
			return (byte.arg2);
		if (argnr == 3)
			return (byte.arg3);
	}
	return (get_opinfo(inst)->v_args[argnr - 1].arg1);
}

int				arg_length(t_args_type type, t_inst inst)
{
	if (type == kTReg)
		return (REG_SIZE_ASM);
	else if (type == kTDir)
		return (get_opinfo(inst)->dir_size);
	else if (type == kTInd)
		return (IND_SIZE_ASM);
	else if (type == kTNone)
		return (0);
	return (0);
}

int				args_length(t_enbyte byte, t_inst inst)
{
	int len;

	len = 1;
	if (is_opcode(inst))
	{
		len += arg_length(get_arg(byte, inst, 1), inst);
		len += arg_length(get_arg(byte, inst, 2), inst);
		len += arg_length(get_arg(byte, inst, 3), inst);
		len += get_opinfo(inst)->has_enbyte ? 1 : 0;
	}
	return (len);
}

/*
**	IS_REGISTRY
**	Checks if given argument is a valid registry
*/

int			is_registry(int arg)
{
	if (arg > 0 && arg <= REG_NUMBER)
		return (true);
	return (false);
}
