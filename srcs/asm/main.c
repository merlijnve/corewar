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

/*
**  TODO
**  - lexical analysis
**	- calculate zjmps and stuff
**  - write to .cor file
*/

int		main(int argc, char **argv)
{
	int		input_fd;
	t_list	*lines;
	t_asm	asmblr;

	ft_bzero(&asmblr, sizeof(asmblr));
	input_fd = check_args(argc, argv, &asmblr);
	// FOR OPENING OF NEW FILE WITH CORRECT RIGHTS
	//output_fd = open("test.cor", O_CREAT | O_RDWR, 0600);
	//close(fd);

	char *file;

	read_file(input_fd, &file);
//	ft_lstrev(&lines);
//	parse_file(lines, &asmblr);

	ft_printf("file:\n%s", file);

	close(input_fd);
	return (0);
}
