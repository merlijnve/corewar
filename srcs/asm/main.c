/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/01 19:24:35 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/08 21:26:23 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include "asm.h"
#include "input_parser.h"
#include "tokenizer.h"
#include "translator.h"
#include "linker.h"

/*
**  TODO
**  - lexical analysis
**	- calculate zjmps and stuff
**  - write to .cor file
*/


static void print_lines(t_list *lines)
{
	ft_printf("LINES:\n ++++ START ++++\n");
	while (lines != NULL)
	{
		ft_printf("line: %.4d | %s\n", lines->content_size, lines->content);
		lines = lines->next;
	}
	ft_printf("++++ END ++++\n\n");
}

static void print_tokens(t_list *lines)
{
	t_tksave *part;

	ft_printf("LINES:\n ++++ START ++++\n");
	while (lines != NULL)
	{
		part = lines->content;
		ft_printf("token: %.3d:%.3d %d | %s\n", part->loc.ln, part->loc.chr, part->token, part->str);
		lines = lines->next;
	}
	ft_printf("++++ END ++++\n\n");
}

static void print_bc(t_asm *asmblr, size_t size)
{
	print_memory(asmblr->bytecode.bytecode, size);
	ft_printf("\n");
}

int		main(int argc, char **argv)
{
	int		input_fd;
	t_asm	*asmblr;
	char 	*file;
	t_list 	*lines;
	t_list 	*tokens;
	t_error error = {};

	lines = NULL;
	tokens = NULL;
	file = NULL;
	asmblr = NULL;
	asmblr = ft_memalloc(sizeof(t_asm));

	if (asmblr == NULL)
		return 0;

	input_fd = check_args(argc, argv, asmblr);

	read_file(input_fd, &file);
	ft_printf("FILE:\n ++++ START ++++\n%s\n ++++ END ++++\n\n", file);

	read_lines(file, &lines);
	print_lines(lines);

	tokens_from_lines(lines, &tokens);
	print_tokens(tokens);

	asmblr->bytecode.bytecode = ft_memalloc(2048); // TODO: move this to somewhere else
	ft_memset(asmblr->bytecode.bytecode, '\x00', 2048);
	asmblr->bytecode.bcpoint = asmblr->bytecode.bytecode;

	print_bc(asmblr, 64);
	if (error.code == kSuccess)
		error.code = translate(tokens, asmblr, &error);
	print_bc(asmblr, 64);
	if (error.code == kSuccess)
		error.code = asm_link(asmblr, &error);
	print_bc(asmblr, 64);

	// error
	if (error.code != kSuccess)
		ft_printf("Error: %.3d Line: %.4d:%.4d [%s]\n", error.code, error.token->loc.ln, error.token->loc.chr, error.token->str);

	close(input_fd);
	return (0);
}
