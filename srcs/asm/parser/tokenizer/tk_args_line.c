/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_args_line.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 22:17:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 22:17:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <op.h>
#include "tokenizer.h"

t_ret	tk_args_line(char *line, t_place loc, t_list **tokens, t_error *error)
{
	t_ret		ret;
	t_tksave	token;

	ret = kSuccess;
	while (ret == kSuccess && line[loc.chr] != '\0')
	{
		while (line[loc.chr] != '\0' && ft_isspace(line[loc.chr]))
			loc.chr++;
		if (line[loc.chr] == SEPARATOR_CHAR)
			ret = get_tk_for_sep(line, &token, &loc, error);
		else if (line[loc.chr] == DIRECT_CHAR)
			ret = get_tk_for_dir(line, &token, &loc, error);
		else if (line[loc.chr] == REGISTER_CHAR)
			ret = get_tk_for_reg(line, &token, &loc, error);
		else if (ft_isalnum(line[loc.chr])
					|| line[loc.chr] == '-' || line[loc.chr] == LABEL_CHAR)
			ret = get_tk_for_ind(line, &token, &loc, error);
		else if (ft_strchr(COMMENT_CHARS, line[loc.chr])
					&& line[loc.chr] != '\0')
			break ;
		else
			return (set_err_loc(loc, kErrorToken, error));
		add_token(tokens, &token);
	}
	return (ret);
}
