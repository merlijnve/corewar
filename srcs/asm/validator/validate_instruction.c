/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator_instruction.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 21:24:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/16 21:24:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

t_inst	is_inst(const char *line)
{
	int			idx;
	t_inst		inst;
	size_t		len;

	idx = 0;
	inst = kInstUndef;
	while (idx < 16 && inst == kInstUndef && line != NULL)
	{
		len = ft_strlen(get_opinfo(idx + 1)->name);
		if (ft_strncmp(line, get_opinfo(idx + 1)->name, len) == 0
			&& (ft_isspace(line[len]) || line[len] == '\0'))
			inst = (t_inst)(idx + 1);
		idx++;
	}
	return (inst);
}

t_ret	validate_instruction(t_tksave *token, t_error *error)
{
	if (token->token == kTokenInstruction && is_inst(token->str) == kInstUndef)
	{
		error->code = kErrorUndefineInstructionError;
		error->token = token;
		return (error->code);
	}
	return (kSuccess);
}
