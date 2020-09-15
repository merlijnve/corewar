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
#include "validator.h"

#include "error.h"

#include "debugging.h" // TODO: Remove

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

static t_ret setup_asmblr(t_asm **asmblr, t_error *error)
{
	t_asm *asmblr_loc;

	asmblr_loc = ft_memalloc(sizeof(t_asm));
	if (asmblr_loc != NULL)
	{
		asmblr_loc->bytecode.bytecode = ft_memalloc(100 + 16);
		asmblr_loc->bytecode.length = (100 + 16);
		if (asmblr_loc->bytecode.bytecode == NULL)
		{
			free(asmblr_loc);
			return (kErrorAlloc);
		}
		asmblr_loc->bytecode.bcpoint = asmblr_loc->bytecode.bytecode;
		*asmblr = asmblr_loc;
		error->token = &error->rtoken;
		error->rtoken.token = kTokenUnknown;
		error->rtoken.loc.chr = 0;
		error->rtoken.loc.ln = 0;
		error->rtoken.str = NULL;
		return (kSuccess);
	}
	return (kErrorAlloc);
}

// TODO: Error for no champ code
// TODO: Handle negative numbers
// TODO: Support _ in link names
// TODO: Support empty comment (with 2 quotes)
// TODO: Handle:	/Users/floris/Documents/GitHub/test_asm/assets/file_parsing/multiline_name_and_comment.s (Tab before .name)
// TODO:			/Users/floris/Documents/GitHub/test_asm/assets/file_parsing/Wall.s (Tab before .name)

int		main(int argc, char **argv)
{
	t_asm		*asmblr;
	t_index		skipln;
	int			fd[2];
	t_error 	error;

	skipln = 0;

	error.code = setup_asmblr(&asmblr, &error);

	if (error.code == kSuccess)
	{
		fd[0] = check_args(argc, argv, asmblr);
		error.file_name = asmblr->file_name;
	}
	if (error.code == kSuccess)
		error.code = read_file(fd[0], &asmblr->file);
	if (error.code == kSuccess)
		error.code = read_lines(asmblr->file, &asmblr->lines);
	if (error.code == kSuccess)
		error.code = get_meta_from_file(asmblr->file, asmblr, &error, &skipln);
	if (error.code == kSuccess)
		error.code = tokens_from_lines(asmblr->lines, &asmblr->tokens, skipln, &error);
	if (error.code == kSuccess)
		error.code = validate_tokens(asmblr->tokens, asmblr, &error);
	if (error.code == kSuccess)
		error.code = translate(asmblr->tokens, asmblr, &error);
	if (error.code == kSuccess)
		error.code = asm_link(asmblr, &error);
	if (error.code == kSuccess)
		error.code = write_file(asmblr, open_file(argv[1]), &error);
	if (error.code != kSuccess)
		print_error(&error, asmblr->lines);

	if (error.code != kSuccess)
		print_tokens(asmblr->tokens);
	if (error.code == kSuccess)
		printf("Succesfully Assembled: %s\n", asmblr->file_name);

	close(fd[0]);
	if (error.code != kSuccess)
		return (1);
	return (0);
}
