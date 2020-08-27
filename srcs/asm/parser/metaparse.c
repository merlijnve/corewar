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

static t_ret get_comment(t_tksave *part, char *file, int *line, int *chr)
{
	
	return 0;
}

static t_line_type get_start(char *file, int *line, int *chr)
{
	t_index idx;

	idx = 0;

	while (file[idx] != '\0')
	{
		if (file[idx] == '\n')
		{
			*line += 1;
			*chr = 1;
		}
		else if (file[idx] == '.')
		{
			if (ft_strcmp(&file[idx], ".comment"))
				return (kCommentLine);
			if (ft_strcmp(&file[idx], ".name"))
				return (kNameLine);
			break;
		}
		idx++;
	}
	return (kUndefinedLine);
}

//static t_ret get_comment(char start)

t_ret	get_meta_from_file(char *file, t_tksave tokens[2], t_error *error)
{
	t_ret	ret;
	int		line;
	int 	chr;
	ret = kSuccess;

	line = 1;
	chr = 1;

	error->error = ret;
	return (ret);
}


//static t_line_type get_first_type(char *file, char **start)
//{
//	char *name;
//	char *comment;
//
//	if (file != NULL)
//	{
//		name = ft_strstr(file, ".name");
//		comment = ft_strstr(file, ".comment");
//		if (name == NULL && comment == NULL)
//			return (kUndefinedLine);
//		if (name > comment && comment != NULL)
//		{
//			*start = comment;
//			return (kCommentLine);
//		}
//		if (comment > name && name != NULL)
//		{
//			*start = name;
//			return (kNameLine);
//		}
//	}
//	return (kUndefinedLine);
//}
//static t_line_type get_start(char *file, int *line)
//{
//	char *start;
//	t_line_type type;
//
//
//
//	return (type);
//}
