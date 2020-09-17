/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer_common_two.c                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 16:11:16 by floris        #+#    #+#                 */
/*   Updated: 2020/09/16 16:29:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include "tokenizer.h"

/*
** TODO: Set correct Error Code
*/

t_ret	get_tk_for_sep
	(char *line, t_tksave *token, t_place *loc, t_error *error)
{
	t_index	idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0'
			&& line[idx + loc->chr] != SEPARATOR_CHAR)
		idx++;
	if (line[idx + loc->chr] == '\0')
		return (kError);
	idx++;
	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	if (*str == '\0')
		return (kErrorToken);
	ft_memcpy(&token->loc, loc, sizeof(t_place));
	token->str = str;
	token->token = kTokenSeperator;
	loc->chr += idx;
	return (kSuccess);
}
