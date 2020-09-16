/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_ldi.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret	translate_ldi(t_asm *asmblr, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bc, kInstLdi);
	put_encode(&asmblr->bc,
		(t_enbyte){tft(parts[0].token), tft(parts[1].token), kTReg, kTNone});
	ret = put_part(asmblr, &parts[0], kInstLdi, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], kInstLdi, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[2], kInstLdi, error);
	return (ret);
}
