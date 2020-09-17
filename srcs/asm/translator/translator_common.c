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

#include "translator.h"

void	put_instruction(t_bytecode *bc, t_inst inst)
{
	bc->last_inst = (bc->bcp - bc->bcdata);
	ft_memcpy(bc->bcp, &inst, 1);
	bc->bcp += 1;
}

void	put_encode(t_bytecode *bc, t_enbyte enbyte)
{
	reverse_eb(&enbyte);
	ft_memcpy(bc->bcp, &enbyte, 1);
	bc->bcp += 1;
}

t_ret	put_registry(t_bytecode *bc, unsigned int reg)
{
	if (reg < 0)
		return (reg);
	ft_memcpy(bc->bcp, &reg, REG_SIZE_ASM);
	bc->bcp += REG_SIZE_ASM;
	return (kSuccess);
}

t_ret	put_indirect(t_asm *asmblr, t_tksave *token, size_t dsize)
{
	t_list *item;
	t_jump *jump;

	if (token->str[0] == LABEL_CHAR)
	{
		jump = ft_memalloc(sizeof(t_jump));
		item = ft_memalloc(sizeof(t_list));
		if (jump == NULL || item == NULL)
			return (kErrorAlloc);
		jump->token = token;
		jump->idx = (asmblr->bc.bcp - asmblr->bc.bcdata);
		jump->ins_idx = asmblr->bc.last_inst;
		jump->type = kTInd;
		item->content = jump;
		item->content_size = 0;
		ft_lstadd(&asmblr->bc.jump, item);
		ft_putmembe(asmblr->bc.bcp, 0x8888888888888888, dsize);
	}
	else
		ft_putmembe(asmblr->bc.bcp, ft_atoi(&token->str[0]), dsize);
	asmblr->bc.bcp += dsize;
	return (kSuccess);
}

t_ret	put_direct(t_asm *asmblr, t_tksave *token, size_t dsize)
{
	t_list *item;
	t_jump *jump;

	if (token->str[0] == DIRECT_CHAR && token->str[1] == LABEL_CHAR)
	{
		jump = ft_memalloc(sizeof(t_jump));
		item = ft_memalloc(sizeof(t_list));
		if (jump == NULL || item == NULL)
			return (kErrorAlloc);
		jump->token = token;
		jump->idx = (asmblr->bc.bcp - asmblr->bc.bcdata);
		jump->ins_idx = asmblr->bc.last_inst;
		jump->type = kTDir;
		item->content = jump;
		item->content_size = 0;
		ft_lstadd(&asmblr->bc.jump, item);
		ft_putmembe(asmblr->bc.bcp, 0x8888888888888888, dsize);
	}
	else
		ft_putmembe(asmblr->bc.bcp, ft_atoi(&token->str[1]), dsize);
	asmblr->bc.bcp += dsize;
	return (kSuccess);
}
