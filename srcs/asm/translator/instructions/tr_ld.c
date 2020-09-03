/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_ld.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_ld(t_asm *asmblr, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bytecode, kInstLd);
	put_encode(&asmblr->bytecode,
				(t_enbyte){tft(parts[0].token), kTReg, kTNone, kTNone});
	ret = put_part(asmblr, &parts[0], kInstLd, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], kInstLd, error);
	return (ret);
}
