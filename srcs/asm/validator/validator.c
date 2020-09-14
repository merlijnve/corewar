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

#include "input_parser.h"
#include "validator.h"

t_ret	validate_instruction(t_tksave *token, t_error *error)
{
	if (token->token == kTokenInstruction && is_inst(token->str) == kInstUndef)
	{
		error->code = kUndefineInstructionError;
		error->token = token;
		return (error->code);
	}
	return (kSuccess);
}

t_ret	validate_tokens(t_list *tokens, t_asm *asmblr, t_error *error)
{
	t_ret		ret;
	t_tksave	*token;

	ret = kSuccess;
	while (tokens != NULL && ret == kSuccess)
	{
		token = tokens->content;
		if (token->token == kTokenInstruction)
			ret = validate_instruction(token, error);
		tokens = tokens->next;
	}
	return (ret);
}
