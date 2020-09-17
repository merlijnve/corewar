/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer_common.c                                 :+:    :+:            */
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

t_ret	get_tk_for_ind
	(char *line, t_tksave *token, t_place *loc, t_error *error)
{
	t_index idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && (ft_isspace(line[idx + loc->chr])
			|| (line[idx + loc->chr] != SEPARATOR_CHAR
			&& !ft_strchr(COMMENT_CHARS, line[idx + loc->chr]))))
		idx++;
	if (line[idx + loc->chr] == '\0' && idx == 0)
		return (kError);
	ft_memcpy(&token->loc, loc, sizeof(t_place));
	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	if (*str == '\0')
		return (kErrorToken);
	token->str = str;
	token->token =
		(line[loc->chr] == LABEL_CHAR) ? kTokenIndLabel : kTokenInd;
	loc->chr += idx;
	return (kSuccess);
}

/*
** TODO: Set correct Error Code
*/

t_ret	get_tk_for_dir
	(char *line, t_tksave *token, t_place *loc, t_error *error)
{
	t_index idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && (ft_isspace(line[idx + loc->chr])
			|| (line[idx + loc->chr] != SEPARATOR_CHAR
			&& !ft_strchr(COMMENT_CHARS, line[idx + loc->chr]))))
		idx++;
	if (line[idx + loc->chr] == '\0' && idx == 0)
		return (kError);
	ft_memcpy(&token->loc, loc, sizeof(t_place));
	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	if (*str == '\0')
		return (kErrorToken);
	token->str = str;
	token->token =
		(line[loc->chr + 1] == LABEL_CHAR) ? kTokenDirLabel : kTokenDir;
	loc->chr += idx;
	return (kSuccess);
}

/*
** TODO: Set correct Error Code
*/

t_ret	get_tk_for_reg
	(char *line, t_tksave *token, t_place *loc, t_error *error)
{
	t_index idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && (ft_isspace(line[idx + loc->chr])
			|| (line[idx + loc->chr] != SEPARATOR_CHAR
			&& !ft_strchr(COMMENT_CHARS, line[idx + loc->chr]))))
		idx++;
	if (line[idx + loc->chr] == '\0' && idx == 0)
		return (kError);
	ft_memcpy(&token->loc, loc, sizeof(t_place));
	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	if (*str == '\0')
		return (kErrorToken);
	token->str = str;
	token->token = kTokenRegister;
	loc->chr += idx;
	return (kSuccess);
}

/*
** TODO: Set correct Error Code
*/

t_ret	get_tk_for_inst
	(char *line, t_tksave *token, t_place *loc, t_error *error)
{
	t_index idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && ft_isalnum(line[idx + loc->chr]))
		idx++;
	if (line[idx + loc->chr] == '\0')
		return (kError);
	ft_memcpy(&token->loc, loc, sizeof(t_place));
	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	if (*str == '\0')
		return (kErrorToken);
	token->str = str;
	token->token = kTokenInstruction;
	loc->chr += idx;
	return (kSuccess);
}

/*
** TODO: Set correct Error Code
*/

t_ret	get_tk_for_label
	(char *line, t_tksave *token, t_place *loc, t_error *error)
{
	t_index	idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && line[idx + loc->chr] != LABEL_CHAR)
		idx++;
	idx++;
	if (line[idx + loc->chr] == '\0' && idx == 0)
		return (kError);
	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	if (*str == '\0')
		return (kErrorToken);
	token->str = str;
	token->token = kTokenLabel;
	token->loc = *loc;
	loc->chr += idx;
	return (kSuccess);
}
