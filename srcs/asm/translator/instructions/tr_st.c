/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_st.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_st(t_asm *asmblr, int partc, t_tksave parts[], t_error *error)
{
	t_ret ret;

	ret = kSuccess;
	put_instruction(&asmblr->bytecode, kInstSt);
	put_encode(&asmblr->bytecode, (t_enbyte){kTReg, tft(parts[1].token), kTNone, kTNone});

	if (ret == kSuccess)
		ret = put_registry(&asmblr->bytecode, asm_regtoint(parts[0].str));
	if (ret != kSuccess)
		error->token = &parts[0];

	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], error);

	error->error = ret;
	return (ret);
}

