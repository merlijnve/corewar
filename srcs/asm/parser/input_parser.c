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

#include "shared_utils.h"

#include "input_parser.h"
#include "tokenizer.h"

t_inst				is_parse_inst(const char *line)
{
	int			idx;
	t_inst		inst;
	size_t		len;
	const char	*start;

	idx = 0;
	inst = kInstNone;
	start = ft_find_set(line, ft_isalpha, ft_isspace_h);
	while (idx < 16 && inst == kInstNone && start != NULL)
	{
		len = ft_strlen(get_opinfo(idx + 1)->name);
		if (ft_strncmp(start, get_opinfo(idx + 1)->name, len) == 0
			&& (ft_isspace(start[len]) || start[len] == '\0'))
			inst = (t_inst)(idx + 1);
		idx++;
	}
	if (inst == kInstNone && start != NULL)
	{
		if (!ft_isvisible(start[0]))
			return (kInstNone);
		return (kInstUndef);
	}
	return (inst);
}

static const char	*find_space(const char *line)
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

static t_line_type	has_label(const char *line)
{
	const char	*sym;
	const char	*space;
	t_inst		type;

	space = NULL;
	sym = ft_find_set(line, ft_isalnum, ft_isspace_h);
	if (sym)
		sym = ft_find_chr(sym, LABEL_CHAR, is_readable);
	if (sym)
		space = find_space(sym);
	if (sym != NULL && (space == NULL || (space != NULL && sym < space)))
	{
		if (ft_find_set(&sym[1], ft_isalpha, ft_isspace_h)
			&& !ft_find_set(&sym[1], is_comment_chr, ft_isspace_h))
		{
			type = is_parse_inst(&sym[1]);
			if (type != kInstNone)
				return (kInstLabelLine);
		}
		else
			return (kLabelLine);
	}
	return (kUndefinedLine);
}

t_line_type			line_type(const char *line)
{
	t_line_type type;

	if (line == NULL)
		return (kUndefinedLine);
	if (ft_find_set(line, is_comment_chr, ft_isspace_h))
		return (kSourceCommentLine);
	if (ft_find_chr(line, '\0', ft_isspace_h))
		return (kEmptyLine);
	type = has_label(line);
	if (type != kUndefinedLine)
		return (type);
	if (is_parse_inst(line) != kInstNone)
		return (kInstLine);
	return (kUndefinedLine);
}
