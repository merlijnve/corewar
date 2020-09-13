/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_arch_checker.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 14:32:10 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static bool is_valid_arg(t_inst inst, t_args_type type, int argnr)
{
	t_enbyte byte;

	byte = get_opinfo(inst)->v_args[argnr - 1];

	// kTNone is used as padding, arg can only be validly kTNone if first
	// item is kTNone
	if (byte.arg1 != kTNone && type == kTNone)
		return (false);

	if (type == byte.arg1
		|| type == byte.arg2
		|| type == byte.arg3
		|| type == byte.arg4)
		return true;
	return (false);
}

// TODO: does it matter if ther is no 0b00 in 4th unused part of enbyte?
bool is_valid_enbyte(t_inst inst, t_enbyte enbyte)
{
	bool ret;

	ret = is_valid_arg(inst, enbyte.arg1, 1);
	if (ret)
		ret = is_valid_arg(inst, enbyte.arg2, 2);
	if (ret)
		ret = is_valid_arg(inst, enbyte.arg3, 3);
	if (ret)
	{
		if (enbyte.arg4 == 0)
			ret = true;
		else
			ret = false;
	}
	return (ret);
}
