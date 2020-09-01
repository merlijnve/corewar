/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_sdi.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_sti(t_asm *asmblr, int partc, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bytecode, kInstSti);
	put_encode(&asmblr->bytecode, (t_enbyte){kTReg, tft(parts[1].token), tft(parts[2].token), kTNone});

	ret = put_part(asmblr, &parts[0], kInstSti, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], kInstSti, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[2], kInstSti, error);

	return (ret);
}
