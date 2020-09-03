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

#include "debugging.h" // TODO: Remove

/*
**  TODO
**  - lexical analysis
**	- calculate zjmps and stuff
**  - write to .cor file
*/

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
	print_file(file);

	read_lines(file, &lines);
	print_lines(lines);

	tokens_from_lines(lines, &tokens);
	print_tokens(tokens);

	asmblr->bytecode.bytecode = ft_memalloc(2048); // TODO: move this to somewhere else
	asmblr->bytecode.bcpoint = asmblr->bytecode.bytecode;
	ft_memset(asmblr->bytecode.bytecode, '\x00', 2048);

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
