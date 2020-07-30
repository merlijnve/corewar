/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 20:58:11 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/07/29 21:07:59 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void        debug_print_map(t_arena *arena)
{
    int fd;

    fd = open(DEBUG_FILE, O_WRONLY | O_APPEND | O_CREAT);

    ft_dprintf(fd, "Hello world!\n");
}