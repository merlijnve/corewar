/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linker.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 22:17:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 22:17:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "linker.h"
#include "translator.h"
#include "shared_utils.h"

/*
** TODO: Remove
*/

#include "debugging.h"

/*
** TODO: this function has to be checked..
** does it compare correctly (it maybe now does)
*/

static int		clean_and_compare(t_jump *jmp, t_marker *mkr)
{
	t_index	sp_jmp;
	t_index	sp_mkr;
	char	*sjmp;
	char	*smkr;

	sp_jmp = 0;
	sp_mkr = 0;
	sjmp = jmp->token->str;
	smkr = mkr->token->str;
	smkr = smkr;

	while (sjmp[sp_jmp] != '\0'
		   && (sjmp[sp_jmp] == LABEL_CHAR || sjmp[sp_jmp] == DIRECT_CHAR))
		sp_jmp++;
	while (is_label_chr(sjmp[sp_jmp]) && is_label_chr(smkr[sp_mkr])
			&& sjmp[sp_jmp] == smkr[sp_mkr])
	{
		sp_jmp++;
		sp_mkr++;
	}
	if ((sjmp[sp_jmp] == '\0' || !is_label_chr(sjmp[sp_jmp]))
		&& (smkr[sp_mkr] == '\0' || !is_label_chr(smkr[sp_mkr])))
		return (1);
	else
		return (0);
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
		if (clean_and_compare(jump, (t_marker *)markers->content))
		{
			found = (t_marker *)markers->content;
			break ;
		}
		markers = markers->next;
	}
	if (found == NULL)
		return (kErrorLinkNotFound);
	*marker = found;
	return (ret);
}

static t_ret	put_link
	(t_bytecode *bc, t_list *markers, t_jump *jump, t_error *error)
{
	t_marker	*res;
	t_ret		ret;
	size_t		size;
	t_inst 		inst;

	ret = find_marker(markers, jump, &res);
	if (ret != kSuccess)
	{
		error->code = ret;
		error->token = jump->token;
		return (ret);
	}
	size = 2;
	inst = bc->bcdata[jump->ins_idx];
	if (jump->type == kTDir && get_opinfo(inst)->dir_size == 4)
		size = 4;
	ft_putmembe(&bc->bcdata[jump->idx], res->idx - jump->ins_idx, size);
	return (kSuccess);
}

t_ret			asm_link(t_asm *asmblr, t_error *error)
{
	t_ret	ret;
	t_list	*jumps;

	ret = kSuccess;
	jumps = asmblr->bc.jump;
	while (jumps != NULL && ret == kSuccess)
	{
		ret = put_link(&asmblr->bc, asmblr->bc.marker, jumps->content, error);
		jumps = jumps->next;
//		print_bc(asmblr, asmblr->bc.length - 16);
	}
	return (ret);
}
