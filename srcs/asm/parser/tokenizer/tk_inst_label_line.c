/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_inst_label_line.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_ret	tk_inst_label_line
	(char *line, t_place loc, t_list **tokens, t_error *error)
{
	t_ret		ret;
	t_tksave	*token;

	token = ft_memalloc(sizeof(t_tksave));
	if (token == NULL)
		return (kErrorAlloc);
	while (line[loc.chr] != '\0' && ft_isspace(line[loc.chr]))
		loc.chr++;
	ret = get_tk_for_label(line, token, &loc);
	add_token(tokens, token);
	if (ret == kSuccess)
		ret = tk_inst_line(line, loc, tokens, error);
	error->code = ret;
	return (ret);
}
