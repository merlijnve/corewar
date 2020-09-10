/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:37:52 by joris         #+#    #+#                 */
/*   Updated: 2020/09/10 13:24:15 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_usage(void)
{
	ft_printf("Usage: ./corewar [-dump N | -n (1-MAX_PLAYERS)] "
		"<champion1.cor> <...>\n");
}

int			main(int argc, char **argv)
{
	t_arena		arena;

	ft_bzero(&arena, sizeof(arena));
	arena.visu_flag = false; // TODO: Is this nessesary here?
	check_args(argc, argv, &arena);
	check_champions(arena.champions, arena.champion_count);
	start_arena(&arena);
	return (EXIT_SUCCESS);
}
