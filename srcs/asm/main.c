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
		ft_printf("line: %.4d | %s\n", 0, lines->content);
		lines = lines->next;
	}
	ft_printf("++++ END ++++\n");
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
	ft_printf("++++ END ++++\n");
}

int		main(int argc, char **argv)
{
	int		input_fd;
	t_asm	asmblr;
	char *file;
	t_list *lines;
	t_list *tokens;

	lines = NULL;
	tokens = NULL;
	file = NULL;
	ft_bzero(&asmblr, sizeof(asmblr));
	input_fd = check_args(argc, argv, &asmblr);

	read_file(input_fd, &file);

	ft_printf("FILE:\n ++++ START ++++\n\n%s\n ++++ END ++++\n\n", file);

	read_lines(file, &lines);
	print_lines(lines);

	tokens_from_lines(lines, &tokens);
	print_tokens(tokens);

	translate(tokens, &asmblr, NULL);

	close(input_fd);
	return (0);
}
