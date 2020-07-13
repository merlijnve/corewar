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

/*
**  TODO
**  - lexical analysis
**	- calculate zjmps and stuff
**  - write to .cor file
*/

int		main(int argc, char **argv)
{
	int		input_fd;
	t_asm	asm_s;

	ft_bzero(&asm_s, sizeof(asm_s));
	input_fd = check_args(argc, argv, &asm_s);
	// FOR OPENING OF NEW FILE WITH CORRECT RIGHTS
	//output_fd = open("test.cor", O_CREAT | O_RDWR, 0600);
	//close(fd);
	close(input_fd);
	return (0);
}
