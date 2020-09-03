//
//  tokenizer_common.c
//  cw-asm
//
//  Created by Floris Fredrikze on 31/08/2020.
//

#include <op.h>

#include "tokenizer.h"

t_ret	get_tk_for_sep(char *line, t_tksave *token, t_place *loc)
{
	t_index idx;
	char 	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && line[idx + loc->chr] != SEPARATOR_CHAR)
		idx++;

	if (line[idx + loc->chr] == '\0')
		return (kError); // TODO: Set correct Error Code
	idx++;

	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	// TODO: remove below..
	if (*str == '\0')
		return (kTokenError);

	ft_memcpy(&token->loc, loc, sizeof(t_place));
	token->str = str;
	token->token = kTokenSeperator;

	loc->chr += idx;

	return (kSuccess);
}

t_ret	get_tk_for_ind(char *line, t_tksave *token, t_place *loc)
{
	t_index idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && (ft_isspace(line[idx + loc->chr]) || line[idx + loc->chr] != SEPARATOR_CHAR))
		idx++;

	if (line[idx + loc->chr] == '\0' && idx == 0)
		return (kError); // TODO: Set correct Error Code

	ft_memcpy(&token->loc, loc, sizeof(t_place));
	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	// TODO: remove below..
	if (*str == '\0')
		return (kTokenError);
	token->str = str;

	if (line[loc->chr + 1] == DIRECT_CHAR)
		token->token = kTokenIndirectLabel;
	else
		token->token = kTokenIndirect;
	loc->chr += idx;

	return (kSuccess);
}

t_ret	get_tk_for_dir(char *line, t_tksave *token, t_place *loc)
{
	t_index idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && (ft_isspace(line[idx + loc->chr]) || line[idx + loc->chr] != SEPARATOR_CHAR))
		idx++;

	if (line[idx + loc->chr] == '\0' && idx == 0)
		return (kError); // TODO: Set correct Error Code

	ft_memcpy(&token->loc, loc, sizeof(t_place));

	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	// TODO: remove below..
	if (*str == '\0')
		return (kTokenError);
	token->str = str;

	if (line[loc->chr + 1] == DIRECT_CHAR)
		token->token = kTokenDirectLabel;
	else
		token->token = kTokenDirect;
	loc->chr += idx;

	return (kSuccess);
}


t_ret	get_tk_for_reg(char *line, t_tksave *token, t_place *loc)
{
	t_index idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && line[idx + loc->chr] != SEPARATOR_CHAR)
		idx++;

	if (line[idx + loc->chr] == '\0' && idx == 0)
		return (kError); // TODO: Set correct Error Code

	ft_memcpy(&token->loc, loc, sizeof(t_place));
	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	// TODO: remove below.. check if can be 0 length.. could be annoying
	if (*str == '\0')
		return (kTokenError);
	token->str = str;
	token->token = kTokenRegister;

	loc->chr += idx;

	return (kSuccess);
}

t_ret	get_tk_for_inst(char *line, t_tksave *token, t_place *loc)
{
	t_index idx;
	char	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && ft_isalnum(line[idx + loc->chr]))
		idx++;

	if (line[idx + loc->chr] == '\0')
		return (kError); // TODO: Set correct Error Code

	ft_memcpy(&token->loc, loc, sizeof(t_place));
	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	// TODO: remove below..
	if (*str == '\0')
		return (kTokenError);
	token->str = str;
	token->token = kTokenInstruction;

	loc->chr += idx;

	return (kSuccess);
}

t_ret	get_tk_for_label(char *line, t_tksave *token, t_place *loc)
{
	t_index idx;
	char 	*str;

	idx = 0;
	while (line[idx + loc->chr] != '\0' && line[idx + loc->chr] != ':')
		idx++;
	idx++;

	if (line[idx + loc->chr] == '\0' && idx == 0)
		return (kError); // TODO: Set correct Error Code

	str = ft_strndup(&line[loc->chr], idx);
	if (str == NULL)
		return (kErrorAlloc);
	// TODO: remove below..
	if (*str == '\0')
		return (kTokenError);
	token->str = str;

	token->token = kTokenLabel;

	loc->chr += idx;

	return (kSuccess);
}
