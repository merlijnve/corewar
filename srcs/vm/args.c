/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   args.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 13:48:52 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/16 14:57:06 by joris         ########   odam.nl         */
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
	int		len;
	int		i;

	len = 1;
	i = 0;
	if (is_opcode(inst))
	{
		while (i < get_opinfo(inst)->argc)
		{
			len += arg_length(get_arg(byte, inst, i + 1), inst);
			i++;
		}
		len += get_opinfo(inst)->has_enbyte ? 1 : 0;
	}
	return (len);
}

/*
**	IS_REGISTRY
**	Checks if given argument is a valid registry
*/

int				is_registry(int arg)
{
	if (arg > 0 && arg <= REG_NUMBER)
		return (true);
	return (false);
}
