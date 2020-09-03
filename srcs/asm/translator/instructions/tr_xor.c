/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_xor.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_xor(t_asm *asmblr, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bytecode, kInstXor);
	put_encode(&asmblr->bytecode,
				(t_enbyte){tft(parts[0].token), tft(parts[1].token), kTReg, kTNone});
	ret = put_part(asmblr, &parts[0], kInstXor, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], kInstXor, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[2], kInstXor, error);
	return (ret);
}
