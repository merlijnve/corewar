/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translator.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

#include "input_parser.h" // for is_inst, maybe move to general location?

static int	tr_argc[17] =
{
	0,1,2,2,3,3,3,3,3,1,3,3,1,2,3,1,1
};

static t_tr_func tr_funcs[17] =
{
	NULL,
	translate_live,
	translate_ld,
	translate_st,
	translate_add,
	translate_sub,
	translate_and,
	translate_or,
	translate_xor,
	translate_zjmp,
	translate_ldi,
	translate_sti,
	translate_fork,
	translate_lld,
	translate_lldi,
	translate_lfork,
	translate_aff
};

static t_ret prepare_tokens(t_list *tokens, t_tksave **tk_arr)
{
	size_t		len;
	t_index		idx;
	t_tksave	*arr;

	idx = 0;

	len =  ft_lstlen(tokens);
 	arr = ft_memalloc(sizeof(t_tksave) * (len + 1));

	if (arr == NULL)
		return (kErrorAlloc);

	while (idx <= len && tokens != NULL)
	{
		if (((t_tksave *)tokens->content)->token != kTokenSeperator)
		{
			ft_memcpy(&arr[idx], tokens->content, sizeof(t_tksave));
			idx++;
		}
		tokens = tokens->next;
	}
	*tk_arr = arr;
	return (kSuccess);
}

t_ret translate(t_list *tokens, t_asm *asmblr, t_error *error)
{
	t_ret		ret;
	t_tksave	*tk_arr;
	t_index		idx;
	t_inst		type;

	idx = 0;
	ret = prepare_tokens(tokens, &tk_arr);

	ft_printf("start asmblr export\n");
	print_memory(asmblr->bytecode.bytecode, 100);
	ft_printf("end asmblr export\n\n");

	while (tk_arr[idx].token != kTokenNone && ret == kSuccess)
	{
		if (tk_arr[idx].token == kTokenInstruction)
		{
			// no check needed, as should already be validated tokens
			type = is_inst(tk_arr[idx].str);
			ret = tr_funcs[type](asmblr, &tk_arr[idx + 1], error);
			idx += tr_argc[type] + 1;
		}
		else if (tk_arr[idx].token == kTokenLabel)
		{
			idx++;
			// create label for current location
		}
		else
			ret = kError; // TODO: find correct error
	}

	ft_printf("start asmblr export\n");
	print_memory(asmblr->bytecode.bytecode, 100);
	ft_printf("end asmblr export\n\n");
	// TODO: linking

	return (ret);
}
