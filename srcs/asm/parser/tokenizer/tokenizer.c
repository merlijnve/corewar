/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tokenizer.h"
#include "input_parser.h"

t_ret add_token(t_list **tokens, t_tksave *token)
{
	t_list *new;
	t_tksave *tkp;

	new = ft_memalloc(sizeof(t_list));
	tkp = ft_memalloc(sizeof(t_tksave));
	if (new == NULL || tkp == NULL)
	{
		free(new);
		free(tkp);
		return (kErrorAlloc);
	}
	ft_memcpy(tkp, token, sizeof(t_tksave));
	new->content = tkp;
	new->next = *tokens;
	*tokens = new;
	return (kSuccess);
}

t_ret tokens_from_lines(t_list *lines, t_list **tokens)
{
	t_ret		ret;
	t_line_type	type;
	ret = kSuccess;

	// SKIPP FIRST PART FOR NOW!
	while (lines != NULL) {
		type = line_type(lines->content);
		if (type == kInstLine || type == kInstLabelLine)
			break ;
		lines = lines->next;
	}

	while (lines != NULL)
	{
		type = line_type(lines->content);
		if (type == kInstLine)
			ret = tk_inst_line(lines->content, (t_place){lines->content_size, 0}, tokens);
		else if (type == kInstLabelLine)
			ret = tk_inst_label_line(lines->content, (t_place){lines->content_size, 0}, tokens);
		else if (type == kLabelLine)
			ret = tk_label_line(lines->content, (t_place){lines->content_size, 0}, tokens);
		lines = lines->next;
	}
	ft_lstrev(tokens);
	return (ret);
}
