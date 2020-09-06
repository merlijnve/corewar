/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/09/06 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include <op.h>

// argc			// 1,2,2,3,3,3,3,3,1,3,3,1,2,3,1,1
// dir size		// 4,4,4,4,4,4,4,4,2,2,2,2,4,2,2,4
// timeout		// 10,5,5,10,10,6,6,6,20,25,25,800,10,50,1000,2

static const t_opinfo	g_opinfo[16] =
{
	{ // live
		.argc = 1, .dir_size = 4, .timeout = 10,
		.has_enbyte = false,
		.v_args =
		{
			{kTDir, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{ // ld
		.argc = 2, .dir_size = 4, .timeout = 5,
		.has_enbyte = true,
		.v_args =
		{
			{kTDir, kTInd, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{ // st
		.argc = 2, .dir_size = 4, .timeout = 5,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTInd, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{ // add
		.argc = 3, .dir_size = 4, .timeout = 10,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{ // sub
		.argc = 3, .dir_size = 4, .timeout = 10,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{ // and
		.argc = 3, .dir_size = 4, .timeout = 6,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{ // or
		.argc = 3, .dir_size = 4, .timeout = 6,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{ // xor
		.argc = 3, .dir_size = 4, .timeout = 6,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
		}
	},
	{ // zjmp
		.argc = 1, .dir_size = 2, .timeout = 20,
		.has_enbyte = false,
		.v_args =
		{
			{kTDir, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{ // ldi
		.argc = 3, .dir_size = 2, .timeout = 25,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTInd, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{ // sti
		.argc = 3, .dir_size = 2, .timeout = 25,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTDir, kTNone, kTNone},
		}
	},
	{ // fork
		.argc = 1, .dir_size = 2, .timeout = 800,
		.has_enbyte = false,
		.v_args =
		{
			{kTDir, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{ // lld
		.argc = 2, .dir_size = 4, .timeout = 10,
		.has_enbyte = true,
		.v_args =
		{
			{kTDir, kTInd, kTNone, kTNone},
			{kTReg, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{ // lldi
		.argc = 3, .dir_size = 2, .timeout = 50,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTDir, kTInd, kTNone},
			{kTReg, kTInd, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{ // lfork
		.argc = 1, .dir_size = 2, .timeout = 1000,
		.has_enbyte = false,
		.v_args =
		{
			{kTDir, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
	{ // aff
		.argc = 1, .dir_size = 4, .timeout = 2,
		.has_enbyte = true,
		.v_args =
		{
			{kTReg, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
			{kTNone, kTNone, kTNone, kTNone},
		}
	},
};

// WARN: do not call code from either ASM or VM here

const t_opinfo *get_opinfo(t_inst intst)
{
	return (&g_opinfo[intst - 1]);
}
