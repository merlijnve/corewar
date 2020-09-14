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
#include "tokenizer.h"

t_inst	is_inst(char *line)
{
	int		idx;
	t_inst	inst;

	idx = 0;
	inst = kInstNone;
	while (idx < 16 && inst == kInstNone)
	{
		if (ft_strcmp(line, get_opinfo(idx + 1)->name) == 0)
			inst = (t_inst)(idx + 1);
		idx++;
	}
	if (inst == kInstNone)
		return (kInstUndef);
	return (inst);
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

	if (line == NULL)
		return (kUndefinedLine);
	if (*line == COMMENT_CHAR)
		return (kSourceCommentLine);
	if (*line == '\0')
		return (kEmptyLine);
	type = has_label(line);
	if (type != kUndefinedLine)
		return (type);
	if (is_inst(line) != kInstNone)
		return (kInstLine);
	return (kUndefinedLine);
}
