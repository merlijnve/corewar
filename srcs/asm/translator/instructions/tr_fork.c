/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_fork.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_fork(t_asm *asmblr, int partc, t_tksave parts[], t_error *error)
{
	t_ret ret;

	ret = kSuccess;
	if (partc != 1)
		ret = kInvalidArgumentCount;
	if (ret == kSuccess)
	{
		put_instruction(&asmblr->bytecode, kInstFork);
		ret = put_direct(asmblr, parts[0].str);
	}
	if (ret != kSuccess)
		error->token = &parts[0];

	error->error = ret;
	return (ret);
}
