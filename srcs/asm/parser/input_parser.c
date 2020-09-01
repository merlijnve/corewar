/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 15:29:33 by floris        #+#    #+#                 */
/*   Updated: 2020/06/11 15:29:35 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <ft_printf.h>
#include <op.h>

#include "input_parser.h"
#include "tokenizer.h"

t_inst	is_inst(char *line)
{
	if (ft_strcmp(line, "add") == 0)
		return (kInstAdd);
	if (ft_strcmp(line, "aff") == 0)
		return (kInstAff);
	if (ft_strcmp(line, "and") == 0)
		return (kInstAnd);
	if (ft_strcmp(line, "fork") == 0)
		return (kInstFork);
	if (ft_strcmp(line, "ld") == 0)
		return (kInstLd);
	if (ft_strcmp(line, "ldi") == 0)
		return (kInstLdi);
	if (ft_strcmp(line, "lfork") == 0)
		return (kInstLfork);
	if (ft_strcmp(line, "live") == 0)
		return (kInstLive);
	if (ft_strcmp(line, "lld") == 0)
		return (kInstLld);
	if (ft_strcmp(line, "lldi") == 0)
		return (kInstLldi);
	if (ft_strcmp(line, "or") == 0)
		return (kInstOr);
	if (ft_strcmp(line, "st") == 0)
		return (kInstSt);
	if (ft_strcmp(line, "sti") == 0)
		return (kInstSti);
	if (ft_strcmp(line, "sub") == 0)
		return (kInstSub);
	if (ft_strcmp(line, "xor") == 0)
		return (kInstXor);
	if (ft_strcmp(line, "zjmp") == 0)
		return (kInstZjmp);
	return (kInstUndef);
}

static void	*find_space(char *line)
{
	t_index idx;

	idx = 0;
	while (line[idx] != '\0')
	{
		if (line[idx] == ' ' || line[idx] == '\t')
			return (&line[idx]);
		idx++;
	}
	return (NULL);
}

static t_line_type	has_label(char *line)
{
	char	*sym;
	char	*space;
	char	*poten; // potential
	t_inst	type;

	sym = ft_strchr(line, LABEL_CHAR);
	space = find_space(line);
	if (sym != NULL && (space == NULL || (space != NULL && sym < space)))
	{
		if (sym[1] != '\0')
		{
			poten = ft_strtrim(&sym[1]);
			type = is_inst(poten);
			free(poten);
			if (type >= 0)
				return (kInstLabelLine);
		}
		else
			return (kLabelLine);
	}
	return (kUndefinedLine);

}

t_line_type	line_type(char *line)
{

	t_line_type type;
	// undefined line if there is no line
	if (line == NULL)
		return (kUndefinedLine);

	if (*line == COMMENT_CHAR)
		return (kSourceCommentLine);

	// if line is empty
	if (*line == '\0')
		return (kEmptyLine);

	// starts with ".name"
	if (ft_strncmp(line, ".name", 5) == 0)
		return (kNameLine);

	// starts with ".comment"
	if (ft_strncmp(line, ".comment", 8) == 0)
		return (kCommentLine);

	type = has_label(line);
	if (type != kUndefinedLine)
		return (type);

	if (is_inst(line) != kInstNone)
		return (kInstLine);

	return (kUndefinedLine);
}

static t_ret	check_line(t_parse_flag *flag, t_parse_state *state, t_line_type type)
{
//	if (type == kUndefinedLine)
//		return (kErrorEncounteredBadLine);
//	else if (*state == kAntsParseState)
//	{
//		if (type == kRoomLine || type == kLinkLine)
//			return (kErrorNoAntsDefined);
//	}
//	else if (*state == kRoomsParseState)
//	{
//		if (type == kAntsLine)
//			return (kErrorOnInput);
//		else if (type == kLinkLine)
//			*state = kLinksParseState;
//	}
//	else if (*state == kLinksParseState)
//	{
//		if (type == kRoomLine || type == kAntsLine)
//			return (kErrorOnInput);
//	}
	return (kSuccess);
}

static char *ft_strstart(char *str)
{
	while (*str != '\0' && ft_isspace(*str))
		str++;
	return (str);
}

t_ret		lines_to_tokens(t_list *lines, t_list **tokens)
{
	t_parse_state	state;
	t_parse_flag	flag;
	t_line_type		type;
	t_ret			ret;

	state = kNoParseState;
	flag = kNoFlag;
	ret = kSuccess;

	*tokens = NULL;

//	tokens_from_lines(lines, tokens);
//	ft_lstrev(tokens);
//	while (tokens != NULL && ret == kSuccess)
//	{
//		tokens = tokens->next;
//	}


	while (lines != NULL && ret == kSuccess)
	{
		type = line_type(ft_strstart(lines->content));
		ret = check_line(&flag, &state, type);
		if (lines->content && ret == kSuccess)
		{
			if (type == kUndefinedLine)
				ft_printf("    kUndefinedLine %.3d: %s\n", lines->content_size, lines->content);
			else if (type == kNameLine)
				ft_printf("         kNameLine %.3d: %s\n", lines->content_size, lines->content);
			else if (type == kCommentLine)
				ft_printf("      kCommentLine %.3d: %s\n", lines->content_size, lines->content);
			else if (type == kInstLine)
				ft_printf("         kInstLine %.3d: %s\n", lines->content_size, lines->content);
			else if (type == kInstLabelLine)
				ft_printf("    kInstLabelLine %.3d: %s\n", lines->content_size, lines->content);
			else if (type == kLabelLine)
				ft_printf("        kLabelLine %.3d: %s\n", lines->content_size, lines->content);
			else if (type == kEmptyLine)
				ft_printf("        kEmptyLine %.3d: %s\n", lines->content_size, lines->content);
			else if (type == kSourceCommentLine)
				ft_printf("kSourceCommentLine %.3d: %s\n", lines->content_size, lines->content);
			else
				ft_printf("THIS SHIT SHOULD NOT HAPPEN: %s\n", lines->content);
		}
		lines = lines->next;
	}
	return (ret);
}
