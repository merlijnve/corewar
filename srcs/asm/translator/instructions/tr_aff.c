/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_aff.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_aff(t_asm *asmblr, int partc, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bytecode, kInstAdd);
	put_encode(&asmblr->bytecode, (t_enbyte){kTDir, kTNone, kTNone, kTNone});

	ret = put_registry(&asmblr->bytecode, asm_regtoint(parts[0].str));
	if (ret != kSuccess)
		error->token = &parts[0];

	error->error = ret;
	return (ret);
}
