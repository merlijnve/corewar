//
//  tk_label_line.c
//  cw-asm
//
//  Created by Floris Fredrikze on 31/08/2020.
//

#include "tokenizer.h"

// TODO: Find a way to break this up a little
t_ret tk_args_line(char *line, t_place loc, t_list **tokens)
{
	t_ret		ret;
	t_tksave	token;
	int			done;

	done = 0;
	ret = kSuccess;
	while (ret == kSuccess && line[loc.chr] != '\0')
	{
		while (line[loc.chr] != '\0' && ft_isspace(line[loc.chr]))
			loc.chr++;
		if (line[loc.chr] == SEPARATOR_CHAR)
		{
			ret = get_tk_for_sep(line, &token, &loc);
			done = 1;
		}
		else if (line[loc.chr] == DIRECT_CHAR)
		{
			ret = get_tk_for_dir(line, &token, &loc);
			done = 1;
		}
		else if (line[loc.chr] == REGISTER_CHAR)
		{
			ret = get_tk_for_reg(line, &token, &loc);
			done = 1;
		}
		else if (ft_isalnum(line[loc.chr]))
		{
			ret = get_tk_for_ind(line, &token, &loc);
			done = 1;
		}
		if (done == 1)
			add_token(tokens, &token);
		done = 0;
	}
	return (ret);
}
