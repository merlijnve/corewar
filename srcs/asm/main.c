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

/*
** TODO: Remove
*/

#include "debugging.h"

static int		open_file(char *str)
{
	size_t	len;
	int		fd;
	char	*fn;

	len = ft_strlen(str);
	fn = ft_strnew(len + 2);
	ft_memcpy(fn, str, len);
	ft_memcpy(&fn[len - 2], ".cor", 4);
	fd = open(fn, O_CREAT | O_RDWR | O_TRUNC, 0600);
	free(fn);
	return (fd);
}

static t_asm	*setup_asmblr(t_error *error)
{
	t_asm *asmblr;

	asmblr = ft_memalloc(sizeof(t_asm));
	if (asmblr != NULL)
	{
		asmblr->bc.bcdata = ft_memalloc(255 + 16);
		asmblr->bc.length = (255 + 16);
		if (asmblr->bc.bcdata == NULL)
		{
			free(asmblr);
			return (NULL);
		}
		asmblr->bc.bcp = asmblr->bc.bcdata;
		error->token = &error->rtoken;
		error->rtoken.token = kTokenUnknown;
		error->rtoken.loc.chr = 0;
		error->rtoken.loc.ln = 0;
		error->rtoken.str = NULL;
		return (asmblr);
	}
	return (NULL);
}

static t_ret	extracted(t_asm **asmblr, t_error *error, int *fd)
{
	t_index		skipln;

	skipln = 0;
	if (error->code == kSuccess)
		error->code = read_file(fd[0], &(*asmblr)->file);
	if (error->code == kSuccess)
		error->code = read_lines((*asmblr)->file, &(*asmblr)->lines);
	if (error->code == kSuccess)
		error->code = get_meta_from_file(
			(*asmblr)->file, *asmblr, error, &skipln);
	if (error->code == kSuccess)
		error->code = tokens_from_lines(
			(*asmblr)->lines, &(*asmblr)->tokens, skipln, error);
	if (error->code == kSuccess)
		error->code = validate_tokens((*asmblr)->tokens, *asmblr, error);
	if (error->code == kSuccess)
		error->code = translate((*asmblr)->tokens, *asmblr, error);
	if (error->code == kSuccess)
		error->code = asm_link(*asmblr, error);
	return (error->code);
}

/*
** TODO: Error for no champ code ?
** Code below to print tokens on error
** if (error.code != kSuccess && asmblr->tokens)
**		print_tokens(asmblr->tokens);
*/

int				main(int argc, char **argv)
{
	t_asm		*asmblr;
	int			fd[2];
	t_error		error;

	error.code = kSuccess;
	asmblr = setup_asmblr(&error);
	if (asmblr == NULL)
		error.code = kErrorAlloc;
	if (error.code == kSuccess)
	{
		fd[0] = check_args(argc, argv, asmblr);
		error.file_name = asmblr->file_name;
		error.code = extracted(&asmblr, &error, fd);
	}
	if (error.code == kSuccess)
		error.code = write_file(asmblr, open_file(argv[1]), &error);
	if (error.code != kSuccess)
		print_error(&error, asmblr->lines);
	close(fd[0]);
	if (error.code != kSuccess)
		return (1);
	return (0);
}
