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

void put_instruction(t_bytecode *bc, t_inst inst)
{
	bc->last_inst = (bc->bcpoint - bc->bytecode);
	ft_memcpy(bc->bcpoint, &inst, 1);
	bc->bcpoint += 1;
}

void put_encode(t_bytecode *bc, t_enbyte enbyte)
{
	reverse_eb(&enbyte);
	ft_memcpy(bc->bcpoint, &enbyte, 1);
	bc->bcpoint += 1;
}

t_ret put_registry(t_bytecode *bc, unsigned int reg)
{
	if (reg < 0)
		return (reg);
	ft_memcpy(bc->bcpoint, &reg, REG_SIZE_ASM);
	bc->bcpoint += REG_SIZE_ASM;
	return (kSuccess);
}

t_ret put_indirect(t_asm *asmblr, t_tksave *token, size_t dsize)
{
	t_list *item;
	t_jump *jump;

	if (token->str[0] == LABEL_CHAR)
	{
		jump = ft_memalloc(sizeof(t_jump));
		item = ft_memalloc(sizeof(t_list));
		if (jump == NULL || item == NULL)
			return kErrorAlloc;
		jump->token = token;
		jump->idx = (asmblr->bytecode.bcpoint - asmblr->bytecode.bytecode);
		jump->ins_idx = asmblr->bytecode.last_inst;
		jump->type = kTInd;
		item->content = jump;
		item->content_size = 0;
		ft_lstadd(&asmblr->bytecode.jump, item);
		ft_putmembe(asmblr->bytecode.bcpoint, 0x8888888888888888, dsize);
	}
	else
		ft_putmembe(asmblr->bytecode.bcpoint, ft_atoi(&token->str[0]), dsize);
	asmblr->bytecode.bcpoint += dsize;
	return (kSuccess);
}

t_ret put_direct(t_asm *asmblr, t_tksave *token, size_t dsize, t_error *error)
{
	t_list *item;
	t_jump *jump;

	if (token->str[0] == DIRECT_CHAR && token->str[1] == LABEL_CHAR)
	{
		jump = ft_memalloc(sizeof(t_jump));
		item = ft_memalloc(sizeof(t_list));
		if (jump == NULL || item == NULL)
			return kErrorAlloc;
		jump->token = token;
		jump->idx = (asmblr->bytecode.bcpoint - asmblr->bytecode.bytecode);
		jump->ins_idx = asmblr->bytecode.last_inst;
		jump->type = kTDir;
		item->content = jump;
		item->content_size = 0;
		ft_lstadd(&asmblr->bytecode.jump, item);
		ft_putmembe(asmblr->bytecode.bcpoint, 0x8888888888888888, dsize);
	}
	else
		ft_putmembe(asmblr->bytecode.bcpoint, ft_atoi(&token->str[1]), dsize);
	asmblr->bytecode.bcpoint += dsize;
	return (kSuccess);
}
