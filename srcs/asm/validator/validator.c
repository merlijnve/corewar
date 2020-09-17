/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:41:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/08 14:41:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared_utils.h"
#include "input_parser.h"
#include "validator.h"

bool	ft_strisdigit_padd(const char *s)
{
	t_index idx;

	idx = 0;
	while (s[idx] != '\0' && !ft_isspace(s[idx]))
	{
		if (!ft_isdigit(s[idx]))
			return (false);
		idx++;
	}
	return (true);
}

t_ret	validate_none(t_tksave *token, t_error *error)
{
	return (set_err_token(token, kErrorTokenUnknown, error));
}

static const t_vl_func	g_vl_funcs[10] =
{
	validate_none,
	validate_label,
	validate_instruction,
	validate_register,
	NULL,
	validate_dir,
	validate_dirlabel,
	validate_ind,
	validate_indlabel,
	validate_none,
};

/*
** 	if (token->token == kTokenSeperator)
**		error->code = validate_seperator(token, error);
*/

t_ret	validate_tokens(t_list *tokens, t_error *error)
{
	t_tksave	*token;
	t_vl_func	func;

	func = NULL;
	while (tokens != NULL && error->code == kSuccess)
	{
		token = tokens->content;
		if (token->token >= 0 && token->token < 10)
			func = g_vl_funcs[token->token];
		if (func != NULL)
			error->code = func(token, error);
		if (error->code == kSuccess && token->token == kTokenInstruction)
			error->code = validate_args(
				tokens->next, is_inst(token->str), error);
		tokens = tokens->next;
	}
	return (error->code);
}
