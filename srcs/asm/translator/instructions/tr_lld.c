/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_llf.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_lld(t_asm *asmblr, int partc, t_tksave parts[], t_error *error)
{
	t_ret ret;

	ret = kSuccess;
	put_instruction(&asmblr->bytecode, kInstLld);
	put_encode(&asmblr->bytecode, (t_enbyte){tft(parts[0].token), kTReg, kTNone, kTNone});

	if (ret == kSuccess)
		ret = put_direct(asmblr, parts[0].str);
	if (ret != kSuccess)
		error->token = &parts[0];

	if (ret == kSuccess)
		ret = put_registry(&asmblr->bytecode, asm_regtoint(parts[1].str));
	if (ret != kSuccess)
		error->token = &parts[1];

	error->error = ret;
	return (ret);
}
