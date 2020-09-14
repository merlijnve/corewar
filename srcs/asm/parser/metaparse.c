/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   metaparse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "metaparse.h"
#include "input_parser.h"

// maybe use more
const char	*find_chr(const char *line, char chr, int (skip)(int chr))
{
	t_index idx;

	idx = 0;
	if (skip != NULL)
		while (line[idx] != '\0' && skip(line[idx]) && line[idx] != chr)
			idx++;
	else
		while (line[idx] != '\0' && line[idx] != chr)
			idx++;

	if (line[idx] == chr)
		return (&line[idx]);
	return (NULL);
}

t_line_type		fline_type(const char *str)
{
	const char *detect;

	if (find_chr(str, '\n', ft_isspace_h))
		return (kEmptyLine);
	if (find_chr(str, '#', ft_isspace_h))
		return (kSourceCommentLine);
	detect = find_chr(str, '.', ft_isspace_h);
	if (detect != NULL)
	{
		if (ft_strncmp(detect,
						COMMENT_CMD_STRING,
						ft_strlen(COMMENT_CMD_STRING)) == 0)
			return (kCommentLine);
		if (ft_strncmp(detect,
						NAME_CMD_STRING,
						ft_strlen(NAME_CMD_STRING)) == 0)
			return (kNameLine);
	}
	return (kUndefinedLine);
}

t_ret			go_next_line(t_index *idx, const char *file)
{
	const char *new_line;

	new_line = find_chr(&file[*idx], '\n', NULL);
	if (new_line == NULL)
		return (kMetaParseError);
	*idx = (new_line - file) + 1;
	return (kSuccess);
}

t_ret	set_error(const char *file, t_index idx, t_ret ret, t_error *error)
{
	error->code = ret;
	error->token = &error->rtoken;
	error->rtoken.loc.ln = ft_chrcnt(file, '\n', idx + 1);
	error->rtoken.loc.chr = 0;
	return (ret);
}

// COMMENT_CMD_STRING COMMENT_LENGTH
t_ret	get_comment(t_asm *asmblr, const char *file, t_index *idx, t_error *error)
{
	const char	*start;
	const char	*end;

	start = ft_strstr(&file[*idx], COMMENT_CMD_STRING);
	end = NULL;
	if (start)
	{
		start = &file[*idx + ft_strlen(COMMENT_CMD_STRING)];
		start = find_chr(start, '\"', ft_isspace_h);
	}
	if (start)
		end = find_chr(&start[1], '\"', NULL);
	if (end && *end == '\"')
	{
		// TODO: check correct length
		if (end - start <= COMMENT_LENGTH)
		{
			ft_memcpy(asmblr->comment, &start[1], end - start - 1);
			*idx = (end - file) + 1;
		}
		else
			return (set_error(file, start - file, kMPNameTooLong, error));
	}
	else
		return (set_error(file, *idx, kMetaParseError, error));
	return kSuccess;
}

t_ret	get_name(t_asm *asmblr, const char *file, t_index *idx, t_error *error)
{
	const char	*start;
	const char	*end;

	start = ft_strstr(&file[*idx], NAME_CMD_STRING);
	end = NULL;
	if (start)
	{
		start = &file[*idx + ft_strlen(NAME_CMD_STRING)];
		start = find_chr(start, '\"', ft_isspace_h);
	}
	if (start)
		end = find_chr(&start[1], '\"', NULL);
	if (end && *end == '\"')
	{
		// TODO: check correct length
		if (end - start <= PROG_NAME_LENGTH)
		{
			ft_memcpy(asmblr->name, &start[1], end - start - 1);
			*idx = (end - file) + 1;
		}
		else
			return (set_error(file, start - file, kMPNameTooLong, error));
	}
	else
		return (set_error(file, *idx, kMetaParseError, error));
	return kSuccess;
}


t_ret	get_meta_from_file
	(const char *file, t_asm *asmblr, t_error *error, t_index *lines)
{
	t_ret		ret;
	t_index		idx;
	t_line_type	type;
	int			state;

	state = 0;
	ret = kSuccess;
	idx = 0;
	while (file[idx] != '\0' && ret == kSuccess
		   && (asmblr->comment[0] == '\0' || asmblr->name[0] == '\0'))
	{
		type = fline_type(&file[idx]);
		if (type == kSourceCommentLine || type == kEmptyLine)
		{
			if (go_next_line(&idx, file) != kSuccess)
				return (set_error(file, idx, kMetaParseError, error));
		}
		else if (type == kCommentLine)
			ret = get_comment(asmblr, file, &idx, error);
		else if (type == kNameLine)
			ret = get_name(asmblr, file, &idx, error);
		else
			return (set_error(file, idx, kMetaParseError, error));
	}
	*lines = ft_chrcnt(file, '\n', idx + 1);
	return (ret);
}
