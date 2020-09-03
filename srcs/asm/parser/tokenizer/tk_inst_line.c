/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_instruction_line.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_ret tk_inst_line(char *line, t_place loc, t_list **tokens)
{
	t_ret		ret;
	t_tksave	*token;

	token = ft_memalloc(sizeof(t_tksave));
	if (token == NULL)
		return (kErrorAlloc);
	while (line[loc.chr] != '\0' && ft_isspace(line[loc.chr]))
		loc.chr++;
	ret = get_tk_for_inst(line, token, &loc);
	add_token(tokens, token);
	if (ret == kSuccess)
		ret = tk_args_line(line, loc, tokens);
	return (ret);
}
