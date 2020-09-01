/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_add.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_add(t_asm *asmblr, t_tksave parts[], t_error *error)
{
	t_ret ret;

	put_instruction(&asmblr->bytecode, kInstAdd);
	put_encode(&asmblr->bytecode, (t_enbyte){kTDir, kTDir, kTDir, kTNone});

	ret = put_part(asmblr, &parts[0], kInstAdd, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[1], kInstAdd, error);
	if (ret == kSuccess)
		ret = put_part(asmblr, &parts[2], kInstAdd, error);

	return (ret);
}
