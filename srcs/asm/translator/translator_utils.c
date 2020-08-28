/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translator_common.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret asm_regtoint(char *str)
{
	int number;

	if (*str != 'r')
		return kError;

	// check if all numbers
	// if (ft_stralpha())

	number = ft_atoi(&str[1]);

	return number >= 0 ? number : kError;
}

t_ret put_part(t_asm *asmblr, t_tksave *part, t_error *error)
{
	t_ret ret;

	ret = kSuccess;
	if (tft(part->token) == kTReg)
		ret = put_registry(&asmblr->bytecode, asm_regtoint(part->str));
	else if (tft(part->token) == kTDir || tft(part->token) == kTInd)
		ret = put_direct(asmblr, part->str);

	if (ret != kSuccess)
		error->token = part;

	return (ret);
}

t_args_type tft(t_asm_token token)
{
	if (token == kTokenDirectLabel)
		return (kTDir);
	if (token == kTokenRegister)
		return (kTReg);
	if (token == kTokenIndirect)
		return (kTInd);
	return (kTNone);
}
