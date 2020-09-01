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
#include "op.h"

void put_instruction(t_bytecode *bc, t_inst inst)
{
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

t_ret put_indirect(t_asm *asmblr, char* indirect, size_t dsize)
{
	t_list *item;
	t_jump *jump;

	if (indirect[0] == LABEL_CHAR)
	{
		jump = ft_memalloc(sizeof(jump));
		item = ft_memalloc(sizeof(item));
		if (jump == NULL || item == NULL)
			return kErrorAlloc;
		jump->label = ft_strdup(indirect);
		jump->place = asmblr->bytecode.bcpoint;
		jump->type = kTInd;
		item->content = jump;
		item->content_size = 0;
		ft_lstadd(&asmblr->jump, item);
		ft_putmemle(asmblr->bytecode.bcpoint, 0x8888888888888888, dsize);
	}
	else
		ft_putmemle(asmblr->bytecode.bcpoint, ft_atoi(&indirect[0]), dsize);
	asmblr->bytecode.bcpoint += dsize;
	return (kSuccess);
}

t_ret put_direct(t_asm *asmblr, char* direct, size_t dsize)
{
	t_list *item;
	t_jump *jump;

	if (direct[0] == DIRECT_CHAR && direct[1] == LABEL_CHAR)
	{
		jump = ft_memalloc(sizeof(jump));
		item = ft_memalloc(sizeof(item));
		if (jump == NULL || item == NULL)
			return kErrorAlloc;
		jump->label = ft_strdup(direct);
		jump->place = asmblr->bytecode.bcpoint;
		jump->type = kTDir;
		item->content = jump;
		item->content_size = 0;
		ft_lstadd(&asmblr->jump, item);
		ft_putmemle(asmblr->bytecode.bcpoint, 0x8888888888888888, dsize);
	}
	else
		ft_putmemle(asmblr->bytecode.bcpoint, ft_atoi(&direct[1]), dsize);
	asmblr->bytecode.bcpoint += dsize;
	return (kSuccess);
}
