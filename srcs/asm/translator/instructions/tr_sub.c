/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_sub.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret	translate_sub(t_asm *asmblr, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bc, kInstSub);
	put_encode(&asmblr->bc, (t_enbyte){kTReg, kTReg, kTReg, kTNone});
	ret = put_part(asmblr, &parts[0], kInstSub, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], kInstSub, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[2], kInstSub, error);
	error->code = ret;
	return (ret);
}
