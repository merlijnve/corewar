//
//  linker.c
//  cw-asm
//
//  Created by Floris Fredrikze on 02/09/2020.
//

#include <stdlib.h>

#include "linker.h"
#include "translator.h"

// TODO: this function has to be checked.. does it compare correctly
static int	clean_and_compare(char *jmp, char *mkr)
{
	t_index	sp_jmp;
	t_index	sp_mkr;

	sp_jmp = 0;
	sp_mkr = 0;

	while (jmp[sp_jmp] != '\0' && !ft_isalnum(jmp[sp_jmp]))
		sp_jmp++;
	while (mkr[sp_mkr] != '\0' && !ft_isalnum(mkr[sp_mkr]))
		sp_mkr++;
	while (ft_isalnum(jmp[sp_jmp]) && ft_isalnum(mkr[sp_mkr])
		   && jmp[sp_jmp] == mkr[sp_mkr])
	{
		sp_jmp++;
		sp_mkr++;
	}
	if (   jmp[sp_jmp] == '\0' || !ft_isalnum(jmp[sp_jmp + 1])
		|| mkr[sp_mkr] == '\0' || !ft_isalnum(mkr[sp_mkr + 1]))
		return 1;
	else
		return 0;
}

static t_ret	find_marker(t_list *markers, t_jump *jump, t_marker **marker)
{
	t_ret		ret;
	t_marker	*found;

	found = NULL;
	ret = kSuccess;
	*marker = NULL;

	while (markers != NULL)
	{
		if (clean_and_compare(jump->token->str, ((t_marker *)markers->content)->token->str))
		{
			found = (t_marker *)markers->content;
			break;
		}
		markers = markers->next;
	}
	if (found == NULL)
		return (kLinkNotFoundError);
	*marker = found;
	return (ret);
}

static t_ret 	put_link(t_bytecode *bc, t_list *markers, t_jump *jump, t_error *error)
{
	t_marker	*res;
	t_ret		ret;
	
	ret = find_marker(markers, jump, &res);

	if (ret != kSuccess)
	{
		error->code = ret;
		error->token = jump->token;
		return ret;
	}

	ft_putmembe(&bc->bytecode[jump->idx], res->idx - jump->ins_idx, jump->type == kTDir ? 2 : 4); // TODO: make this correct size alwasy

	return kSuccess;
}

t_ret	asm_link(t_asm *asmblr, t_error *error)
{
	t_ret	ret;
	t_list	*jumps;

	ret = kSuccess;
	jumps = asmblr->bytecode.jump;

	while (jumps != NULL && ret == kSuccess)
	{
		ret = put_link(&asmblr->bytecode, asmblr->bytecode.marker, jumps->content, error);
		jumps = jumps->next;
	}

	return (ret);
}
