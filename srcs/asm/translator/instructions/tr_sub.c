/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_sub.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_sub(t_asm *asmblr, int partc, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bytecode, kInstSub);
	put_encode(&asmblr->bytecode, (t_enbyte){kTDir, kTDir, kTDir, kTNone});

	ret = put_part(asmblr, &parts[0], kInstSub, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], kInstSub, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[2], kInstSub, error);

	error->error = ret;
	return (ret);
}

