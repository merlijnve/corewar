/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_lldi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret	translate_lldi(t_asm *asmblr, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bc, kInstLldi);
	put_encode(&asmblr->bc,
		(t_enbyte){tft(parts[0].token), tft(parts[1].token), kTReg, kTNone});
	ret = put_part(asmblr, &parts[0], kInstLldi, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], kInstLldi, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[2], kInstLldi, error);
	return (ret);
}
