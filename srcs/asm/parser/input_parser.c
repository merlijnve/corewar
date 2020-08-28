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
#include "input_parser.h"

static t_inst	is_inst(char *line)
{
	if (ft_strncmp(line, "add", 3) == 0)
		return (kInstAdd);
	if (ft_strncmp(line, "aff", 3) == 0)
		return (kInstAff);
	if (ft_strncmp(line, "and", 3) == 0)
		return (kInstAnd);
	if (ft_strncmp(line, "fork", 4) == 0)
		return (kInstFork);
	if (ft_strncmp(line, "ld", 2) == 0)
		return (kInstLd);
	if (ft_strncmp(line, "ldi", 3) == 0)
		return (kInstLdi);
	if (ft_strncmp(line, "lfork", 5) == 0)
		return (kInstLfork);
	if (ft_strncmp(line, "live", 4) == 0)
		return (kInstLive);
	if (ft_strncmp(line, "lld", 3) == 0)
		return (kInstLld);
	if (ft_strncmp(line, "lldi", 4) == 0)
		return (kInstLldi);
	if (ft_strncmp(line, "or", 2) == 0)
		return (kInstOr);
	if (ft_strncmp(line, "st", 2) == 0)
		return (kInstSt);
	if (ft_strncmp(line, "sti", 3) == 0)
		return (kInstSti);
	if (ft_strncmp(line, "sub", 3) == 0)
		return (kInstSub);
	if (ft_strncmp(line, "xor", 3) == 0)
		return (kInstXor);
	if (ft_strncmp(line, "zjmp", 4) == 0)
		return (kInstZjmp);
	return (kInstNone);
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

	sym = ft_strchr(line, ':');
	space = find_space(line);
	if (sym != NULL && (space == NULL || (space != NULL && sym < space)))
	{
		if (sym[1] != '\0' || sym[1] != '\n' )
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

static t_line_type	line_type(char *line)
{

	t_line_type type;
	// undefined line if there is no line
	if (line == NULL)
		return (kUndefinedLine);

	if (*line == '#')
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

t_ret		parse_file(t_list *lines, t_asm *asmblr)
{
	t_parse_state	state;
	t_parse_flag	flag;
	t_line_type		type;
	t_ret			ret;

	state = kNoParseState;
	flag = kNoFlag;
	ret = kSuccess;
	while (lines != NULL && ret == kSuccess)
	{
		type = line_type(ft_strstart(lines->content));
		ret = check_line(&flag, &state, type);
		if (lines->content && ret == kSuccess)
		{
			if (type == kUndefinedLine)
				ft_printf("    kUndefinedLine: %s\n", lines->content);
			if (type == kUndefinedLine)
				ft_printf("         kNameLine: %s\n", lines->content);
			if (type == kUndefinedLine)
				ft_printf("      kCommentLine: %s\n", lines->content);
			if (type == kUndefinedLine)
				ft_printf("         kInstLine: %s\n", lines->content);
			if (type == kUndefinedLine)
				ft_printf("    kInstLabelLine: %s\n", lines->content);
			if (type == kUndefinedLine)
				ft_printf("        kLabelLine: %s\n", lines->content);
			if (type == kUndefinedLine)
				ft_printf("        kEmptyLine: %s\n", lines->content);
			if (type == kUndefinedLine)
				ft_printf("kSourceCommentLine: %s\n", lines->content);
			else
				ft_printf("THIS SHIT SHOULD NOT HAPPEN: %s\n", lines->content);
		}
		lines = lines->next;
	}
	return (ret);
}
