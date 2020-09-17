/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator_args.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 21:24:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/16 21:24:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

#include "shared_utils.h"
#include "translator.h"

static bool	is_valid_arg(t_inst inst, t_args_type type, t_index argnr)
{
	t_enbyte byte;

	byte = get_opinfo(inst)->v_args[argnr - 1];
	if (byte.arg1 != kTNone && type == kTNone)
		return (false);
	if (type == byte.arg1
		|| type == byte.arg2
		|| type == byte.arg3
		|| type == byte.arg4)
		return (true);
	return (false);
}

static bool	is_argument(t_tksave *token)
{
	if (token->token == kTokenRegister
		|| token->token == kTokenSeperator
		|| token->token == kTokenDir
		|| token->token == kTokenDirLabel
		|| token->token == kTokenInd
		|| token->token == kTokenIndLabel)
	{
		return (true);
	}
	return (false);
}

t_ret		check_arg(t_index idx, t_inst inst, t_tksave *token, t_error *error)
{
	t_args_type type;

	type = tft(token->token);
	if (is_valid_arg(inst, type, idx))
		return (kSuccess);
	return (kError);
}

t_ret		validate_args(t_list *tkns, t_inst inst, t_error *error)
{
	t_index		idx;
	t_tksave	*token;
	t_tksave	*last;

	idx = 1;
	if (tkns != NULL)
	{
		last = tkns->content;
		while (inst != kInstUndef && inst != kInstNone
				&& idx <= get_opinfo(inst)->argc)
		{
			if (tkns == NULL || !is_argument(tkns->content))
				return (set_err_token(last, kErrorInvalidArgCount, error));
			token = tkns->content;
			if (!is_valid_arg(inst, tft(token->token), idx))
				return (set_err_token(token, kErrorWrongArgType, error));
			idx++;
			last = token;
			tkns = tkns->next;
			if (tkns && ((t_tksave *)tkns->content)->token == kTokenSeperator
				&& last->token != kTokenSeperator)
				tkns = tkns->next;
		}
	}
	return (kSuccess);
}
