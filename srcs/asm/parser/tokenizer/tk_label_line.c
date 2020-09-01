//
//  tk_label_line.c
//  cw-asm
//
//  Created by Floris Fredrikze on 31/08/2020.
//

#include "tokenizer.h"

t_ret tk_label_line(char *line, t_place loc, t_list **tokens)
{
	t_ret		ret;
	t_tksave	*token;

	token = ft_memalloc(sizeof(t_tksave));
	if (token == NULL)
		return (kErrorAlloc);

	while (line[loc.chr] != '\0' && ft_isspace(line[loc.chr]))
		loc.chr++;

	ret = get_tk_for_label(line, token, &loc);
	add_token(tokens, token);

	return (ret);
}
