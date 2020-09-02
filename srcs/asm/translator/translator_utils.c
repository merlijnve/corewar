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

static int inst_ret_size[17] =
{
	0,4,4,4,4,4,4,4,4,2,2,2,2,4,2,2,4
};

static int 	ret_size(t_inst type)
{
	return ((type <= 16 && type >= 1) ? inst_ret_size[type] : 0);
}

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

void	reverse_eb(t_enbyte *eb)
{
	t_enbyte bc;

	bc = *eb;

	eb->arg1  = bc.empty;
	eb->arg2  = bc.arg3;
	eb->arg3  = bc.arg2;
	eb->empty = bc.arg1;
}

t_ret	put_part(t_asm *asmblr, t_tksave *part, t_inst inst, t_error *error)
{
	t_ret ret;

	ret = kSuccess;
	if (tft(part->token) == kTReg)
		ret = put_registry(&asmblr->bytecode, asm_regtoint(part->str));
	else if (tft(part->token) == kTDir)
		ret = put_direct(asmblr, part, ret_size(inst));
	else if (tft(part->token) == kTInd)
		ret = put_indirect(asmblr, part, 2);

	if (ret != kSuccess)
		error->token = part;

	error->error = ret;
	return (ret);
}

t_args_type tft(t_asm_token token)
{
	if (token == kTokenDirectLabel || token == kTokenDirect)
		return (kTDir);
	if (token == kTokenIndirectLabel || token == kTokenIndirect)
		return (kTInd);
	if (token == kTokenRegister)
		return (kTReg);
	return (kTNone);
}
