/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translator.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "translator.h"
#include "input_parser.h"
#include "debugging.h"

static const t_tr_func	g_tr_funcs[17] =
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

static t_ret			prepare_tokens(t_list *tokens, t_tksave **tk_arr)
{
	size_t		len;
	t_index		idx;
	t_tksave	*arr;

	idx = 0;
	len = ft_lstlen(tokens);
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

static t_ret			put_marker(t_asm *asmblr, t_tksave *part)
{
	t_ret		ret;
	t_list		*item;
	t_marker	*marker;

	ret = kSuccess;
	item = ft_memalloc(sizeof(t_list));
	marker = ft_memalloc(sizeof(t_marker));
	if (item == NULL || marker == NULL)
	{
		free(item);
		free(marker);
		return (kErrorAlloc);
	}
	marker->token = part;
	marker->idx = (asmblr->bc.bcp - asmblr->bc.bcdata);
	item->content = marker;
	ft_lstadd(&asmblr->bc.marker, item);
	return (ret);
}

static t_ret			extracted
	(t_asm *asmblr, t_error *error, t_index *idx, t_tksave *tk_arr)
{
	t_ret		ret;
	t_args_type	type;

	ret = kSuccess;
	while (ret == kSuccess && tk_arr[*idx].token != kTokenNone)
	{
		if (tk_arr[*idx].token == kTokenInstruction)
		{
			type = is_parse_inst(tk_arr[*idx].str);
			ret = g_tr_funcs[type](asmblr, &tk_arr[*idx + 1], error);
			*idx += get_opinfo(type)->argc + 1;
		}
		else if (tk_arr[*idx].token == kTokenLabel)
		{
			put_marker(asmblr, &tk_arr[*idx]);
			*idx += 1;
		}
		else
			ret = set_err_token(&tk_arr[*idx], kErrorTranslation, error);
	}
	return (ret);
}

t_ret					translate(t_list *tokens, t_asm *asmblr, t_error *error)
{
	t_ret		ret;
	t_tksave	*tk_arr;
	t_index		idx;

	idx = 0;
	tk_arr = NULL;
	ret = prepare_tokens(tokens, &tk_arr);
	if (ret == kSuccess)
		ret = extracted(asmblr, error, &idx, tk_arr);
	if (tk_arr == NULL || tk_arr[idx].token != kTokenNone)
		return (set_err_token(&tk_arr[idx], kErrorTranslation, error));
	return (ret);
}
