/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_and.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_and(t_asm *asmblr, int partc, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bytecode, kInstAnd);
	put_encode(&asmblr->bytecode, (t_enbyte){tft(parts[0].token), tft(parts[1].token), kTReg, kTNone});

	ret = put_part(asmblr, &parts[0], error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], error);

	if (ret == kSuccess)
		ret = put_registry(&asmblr->bytecode, asm_regtoint(parts[2].str));
	if (ret != kSuccess)
		error->token = &parts[2];

	error->error = ret;
	return (ret);
}
