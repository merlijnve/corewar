/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_or.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_or(t_asm *asmblr, int partc, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bytecode, kInstOr);
	put_encode(&asmblr->bytecode, (t_enbyte){tft(parts[0].token), tft(parts[1].token), kTReg, kTNone});

	ret = put_part(asmblr, &parts[0], kInstOr, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], kInstOr, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[2], kInstOr, error);

	return (ret);
}
