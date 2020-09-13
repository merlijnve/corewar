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

#include <stdlib.h>
#include <libft.h>

#include "asm.h"
#include "check_args.h"
#include "input_parser.h"
#include "metaparse.h"
#include "tokenizer.h"
#include "translator.h"
#include "linker.h"

#include "write_file.h"

#include "debugging.h" // TODO: Remove

/*
**  TODO
**  - lexical analysis
**	- calculate zjmps and stuff
**  - write to .cor file
*/

static int open_file(char *str)
{
	size_t len;
	int fd;
	char *fn;

	len = ft_strlen(str);
	fn = ft_strnew(len + 2);
	ft_memcpy(fn, str, len);
	ft_memcpy(&fn[len - 2], ".cor", 4);
	fd = open(fn, O_CREAT | O_RDWR | O_TRUNC, 0600);
	free(fn);
	return fd;
}

static t_ret setup_asmblr(t_asm **asmblr)
{
	t_asm *asmblr_loc;

	asmblr_loc = ft_memalloc(sizeof(t_asm));
	if (asmblr_loc != NULL)
	{
		asmblr_loc->bytecode.bytecode = ft_memalloc(CHAMP_MAX_SIZE + 16);
		if (asmblr_loc->bytecode.bytecode == NULL)
		{
			free(asmblr_loc);
			return (kErrorAlloc);
		}
		asmblr_loc->bytecode.bcpoint = asmblr_loc->bytecode.bytecode;
		*asmblr = asmblr_loc;
		return (kSuccess);
	}
	return (kErrorAlloc);
}

int		main(int argc, char **argv)
{
	int		fd[2];
	t_asm	*asmblr;
	char 	*file;
	t_list 	*lines;
	t_list 	*tokens;
	t_error error = {};

	lines = NULL;
	tokens = NULL;
	file = NULL;

	error.code = setup_asmblr(&asmblr);

	if (error.code != kSuccess)
		return 0;

	fd[0] = check_args(argc, argv, asmblr);

	read_file(fd[0], &file);
	print_file(file);

	read_lines(file, &lines);
	print_lines(lines);

	t_index linecnt;
	linecnt = 0;
	if (error.code == kSuccess)
		error.code = get_meta_from_file(file, asmblr, &error, &linecnt);
	if (error.code == kSuccess)
		error.code = tokens_from_lines(lines, &tokens, linecnt);
	print_tokens(tokens)
	if (error.code == kSuccess)
		error.code = translate(tokens, asmblr, &error);
	if (error.code == kSuccess)
		error.code = asm_link(asmblr, &error);
	if (error.code == kSuccess)
		error.code = write_file(asmblr, open_file(argv[1]), &error);
	if (error.code != kSuccess)
		ft_printf("Error: %.3d Line: %.4d:%.4d [%s]\n", error.code, error.token->loc.ln, error.token->loc.chr, error.token->str);

	close(fd[0]);
	return (0);
}
