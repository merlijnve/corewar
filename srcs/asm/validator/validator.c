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

t_ret	validate_none(t_tksave *token, t_error *error)
{
	return (set_err_token(token, kErrorTokenUnknown, error));
}

/*
** 	if (token->token == kTokenSeperator)
**		error->code = validate_seperator(token, error);
*/

t_ret	validate_tokens(t_list *tokens, t_asm *asmblr, t_error *error)
{
	t_tksave	*token;

	while (tokens != NULL && error->code == kSuccess)
	{
		token = tokens->content;
		if (token->token == kTokenNone || token->token == kTokenUnknown)
			error->code = validate_none(token, error);
		else if (token->token == kTokenLabel)
			error->code = validate_label(token, error);
		else if (token->token == kTokenInstruction)
			error->code = validate_instruction(token, error);
		else if (token->token == kTokenRegister)
			error->code = validate_register(token, error);
		else if (token->token == kTokenDir)
			error->code = validate_dir(token, error);
		else if (token->token == kTokenDirLabel)
			error->code = validate_dirlabel(token, error);
		else if (token->token == kTokenInd)
			error->code = validate_ind(token, error);
		else if (token->token == kTokenIndLabel)
			error->code = validate_indlabel(token, error);
		tokens = tokens->next;
	}
	return (error->code);
}
