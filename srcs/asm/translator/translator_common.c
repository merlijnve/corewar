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
	ft_memcpy(bc->bcpoint, &enbyte, 1);
	bc->bcpoint += 1;
}

t_ret put_registry(t_bytecode *bc, unsigned int reg)
{
	if (reg < 0)
		return (reg);
	ft_memcpy(bc->bcpoint, &reg, REG_SIZE);
	bc->bcpoint += REG_SIZE;
	return (kSuccess);
}

t_ret put_direct(t_asm *asmblr, char* direct)
{
	int number;
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
		item->content = jump;
		item->content_size = 0;
		ft_lstadd(&asmblr->jump, item);
		ft_bzero(asmblr->bytecode.bcpoint, DIR_SIZE);
	}
	else
	{
		number = ft_atoi(&direct[1]);
		ft_memcpy(asmblr->bytecode.bcpoint, &number, DIR_SIZE);
	}
	asmblr->bytecode.bcpoint += REG_SIZE;
	return (kSuccess);
}
