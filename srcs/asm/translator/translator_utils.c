/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translator_common.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "translator.h"

static int		dir_size(t_inst type)
{
	return ((type <= 16 && type >= 1) ? get_opinfo(type)->dir_size : 0);
}

static t_ret	check_and_resize(t_asm *asmblr)
{
	t_byte *bc;
	t_byte *bcp;
	size_t len;

	bc = asmblr->bc.bcdata;
	bcp = asmblr->bc.bcp;
	len = bcp - bc;
	if (len >= (asmblr->bc.length - 32))
	{
		asmblr->bc.length += 128;
		asmblr->bc.bcdata = ft_memalloc(asmblr->bc.length);
		if (asmblr->bc.bcdata == NULL)
		{
			free(bc);
			return (kErrorAlloc);
		}
		ft_memcpy(asmblr->bc.bcdata, bc, len);
		asmblr->bc.bcp = asmblr->bc.bcdata + (bcp - bc);
		free(bc);
	}
	return (kSuccess);
}

void			reverse_eb(t_enbyte *eb)
{
	t_enbyte bc;

	bc = *eb;
	eb->arg1 = bc.arg4;
	eb->arg2 = bc.arg3;
	eb->arg3 = bc.arg2;
	eb->arg4 = bc.arg1;
}

t_ret			put_part
	(t_asm *asmblr, t_tksave *part, t_inst inst, t_error *error)
{
	t_ret ret;

	check_and_resize(asmblr);
	ret = kSuccess;
	if (tft(part->token) == kTReg)
		ret = put_registry(&asmblr->bc, asm_regtoint(part->str));
	else if (tft(part->token) == kTDir)
		ret = put_direct(asmblr, part, dir_size(inst));
	else if (tft(part->token) == kTInd)
		ret = put_indirect(asmblr, part, 2);
	if (ret != kSuccess)
		error->token = part;
	error->code = ret;
	return (ret);
}

t_args_type		tft(t_asm_token token)
{
	if (token == kTokenDirLabel || token == kTokenDir)
		return (kTDir);
	if (token == kTokenIndLabel || token == kTokenInd)
		return (kTInd);
	if (token == kTokenRegister)
		return (kTReg);
	return (kTNone);
}
