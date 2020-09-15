/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op_arg_checker.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/09/15 02:16:26 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static bool	is_valid_arg(t_inst inst, t_args_type type, int argnr)
{
	t_enbyte byte;

	byte = get_opinfo(inst)->v_args[argnr - 1];
	if (byte.arg1 != kTNone && type == kTNone)
		return (false);
	if (type == byte.arg1
	|| type == byte.arg2
	|| type == byte.arg3
	|| type == byte.arg4)
		return (true);
	return (false);
}

bool		is_valid_enbyte(t_inst inst, t_enbyte enbyte)
{
	bool ret;

	ret = is_valid_arg(inst, enbyte.arg1, 1);
	if (ret)
		ret = is_valid_arg(inst, enbyte.arg2, 2);
	if (ret)
		ret = is_valid_arg(inst, enbyte.arg3, 3);
	if (ret)
		ret = (enbyte.arg4 == kTNone);
	return (ret);
}
