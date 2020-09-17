/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/09/17 01:41:58 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>

static const t_opinfo	g_opinfo[16] =
{
	{
		.name = "live",
		.argc = 1, .dir_size = 4, .timeout = 10,
		.has_enbyte = false,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTDir, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "ld",
		.argc = 2, .dir_size = 4, .timeout = 5,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTDir, kTInd, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "st",
		.argc = 2, .dir_size = 4, .timeout = 5,
		.has_enbyte = true,
		.needs_address = true,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTInd, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "add",
		.argc = 3, .dir_size = 4, .timeout = 10,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "sub",
		.argc = 3, .dir_size = 4, .timeout = 10,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "and",
		.argc = 3, .dir_size = 4, .timeout = 6,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "or",
		.argc = 3, .dir_size = 4, .timeout = 6,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "xor",
		.argc = 3, .dir_size = 4, .timeout = 6,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "zjmp",
		.argc = 1, .dir_size = 2, .timeout = 20,
		.has_enbyte = false,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTDir, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "ldi",
		.argc = 3, .dir_size = 2, .timeout = 25,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "sti",
		.argc = 3, .dir_size = 2, .timeout = 25,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTNone, kTNone},
		}
	},
	{
		.name = "fork",
		.argc = 1, .dir_size = 2, .timeout = 800,
		.has_enbyte = false,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTDir, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "lld",
		.argc = 2, .dir_size = 4, .timeout = 10,
		.has_enbyte = true,
		.needs_address = true,
		.mod_trunc = false,
		.v_args =
		{
			{kTDir, kTInd, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "lldi",
		.argc = 3, .dir_size = 2, .timeout = 50,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "lfork",
		.argc = 1, .dir_size = 2, .timeout = 1000,
		.has_enbyte = false,
		.needs_address = false,
		.mod_trunc = false,
		.v_args =
		{
			{kTDir, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{
		.name = "aff",
		.argc = 1, .dir_size = 4, .timeout = 2,
		.has_enbyte = true,
		.needs_address = false,
		.mod_trunc = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
};

const t_opinfo	*get_opinfo(t_inst intst)
{
	return (&g_opinfo[intst - 1]);
}
