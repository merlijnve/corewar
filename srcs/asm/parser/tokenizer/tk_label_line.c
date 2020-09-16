//
//  tk_label_line.c
//  cw-asm
//
//  Created by Floris Fredrikze on 31/08/2020.
//

#include "shared_utils.h"
#include "tokenizer.h"

t_ret tk_label_line(char *line, t_place loc, t_list **tokens, t_error *error)
{
	t_ret		ret;
	t_tksave	*token;

	token = ft_memalloc(sizeof(t_tksave));
	if (token == NULL)
		return (kErrorAlloc);
	while (line[loc.chr] != '\0' && ft_isspace(line[loc.chr]))
		loc.chr++;
	ret = get_tk_for_label(line, token, &loc, error);
	add_token(tokens, token);
	if (!ft_find_chr(&line[loc.chr], '\0', ft_isspace_h)
		&& !ft_find_set(&line[loc.chr], is_comment_chr, ft_isspace_h))
	{
		if (ft_find_set(&line[loc.chr], ft_isvisible, ft_isspace_h))
			loc.chr += ft_find_set(&line[loc.chr], ft_isvisible, ft_isspace_h) - &line[loc.chr];
		return(set_err_loc(loc, kErrorGarbageFound, error));
	}
	return (ret);
}
