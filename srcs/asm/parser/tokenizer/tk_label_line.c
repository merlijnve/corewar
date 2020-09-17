/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tk_label_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 22:17:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 22:17:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "shared_utils.h"
#include "tokenizer.h"

t_ret	tk_label_line(char *line, t_place loc, t_list **tokens, t_error *error)
{
	t_ret		ret;
	t_tksave	token;

	bzero(&token, sizeof(t_tksave));
	while (line[loc.chr] != '\0' && ft_isspace(line[loc.chr]))
		loc.chr++;
	ret = get_tk_for_label(line, &token, &loc);
	add_token(tokens, &token);
	if (!ft_find_chr(&line[loc.chr], '\0', ft_isspace_h)
		&& !ft_find_set(&line[loc.chr], is_comment_chr, ft_isspace_h))
	{
		if (ft_find_set(&line[loc.chr], ft_isvisible, ft_isspace_h))
			loc.chr += ft_find_set(&line[loc.chr], ft_isvisible, ft_isspace_h)
						- &line[loc.chr];
		return (set_err_loc(loc, kErrorGarbageFound, error));
	}
	return (ret);
}
