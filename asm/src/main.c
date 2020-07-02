/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/01 19:24:35 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/02 12:44:14 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/asm.h"

/*
**  TODO
**  - lexical analysis
**  - write to .cor file
*/

int     main(void)
{
    int fd;

    fd = open("test.cor", O_CREAT | O_RDWR, 0777);
    ft_printf("fd: %i\n");
    ft_putstr_fd("testing\n", fd);
}
