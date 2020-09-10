/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:37:52 by joris         #+#    #+#                 */
/*   Updated: 2020/09/10 14:03:38 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump N | -n (1-MAX_PLAYERS)] "
		"<champion1.cor> <...>");
}

int			main(int argc, char **argv)
{
	t_arena		arena;

	ft_bzero(&arena, sizeof(arena));
	check_args(argc, argv, &arena);
	check_champions(arena.champions, arena.champion_count);
	vm_start(&arena);
	return (EXIT_SUCCESS);
}
