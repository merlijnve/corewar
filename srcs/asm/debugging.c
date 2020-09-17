/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debugging.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 15:29:33 by floris        #+#    #+#                 */
/*   Updated: 2020/06/11 15:29:35 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

#include "debugging.h"

#pragma mark - printing utils

void		print_file(char *file)
{
	ft_printf("FILE:\n ++++ START ++++\n%s\n ++++ END ++++\n\n", file);
}

void		print_lines(t_list *lines)
{
	ft_printf("LINES:\n ++++ START ++++\n");
	while (lines != NULL)
	{
		ft_printf("line: %.4d | %s\n", lines->content_size, lines->content);
		lines = lines->next;
	}
	ft_printf("++++ END ++++\n\n");
}

static char	*token_type_str(t_asm_token token)
{
	if (token == kTokenNone)
		return ("kTokenNone");
	else if (token == kTokenLabel)
		return ("kTokenLabel");
	else if (token == kTokenInstruction)
		return ("kTokenInstruction");
	else if (token == kTokenRegister)
		return ("kTokenRegister");
	else if (token == kTokenSeperator)
		return ("kTokenSeperator");
	else if (token == kTokenDir)
		return ("kTokenDir");
	else if (token == kTokenDirLabel)
		return ("kTokenDirLabel");
	else if (token == kTokenInd)
		return ("kTokenInd");
	else if (token == kTokenIndLabel)
		return ("kTokenIndLabel");
	else if (token == kTokenUnknown)
		return ("kTokenUnknown");
	return (NULL);
}

void		print_tokens(t_list *tokens)
{
	t_tksave *part;

	ft_printf(" ==== ==== ==== START TOKENS ==== ==== ====\n");
	while (tokens != NULL)
	{
		part = tokens->content;
		ft_printf("token: %.3d:%.3d %-18s | %s\n",
					part->loc.ln, part->loc.chr,
					token_type_str(part->token), part->str);
		tokens = tokens->next;
	}
	ft_printf(" ==== ==== ====  END TOKENS  ==== ==== ====\n\n");
}

void		print_bc(t_asm *asmblr, size_t size)
{
	debug_print_mem(asmblr->bc.bcdata, size);
	ft_printf("\n");
}
