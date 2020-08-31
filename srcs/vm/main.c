/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:37:52 by joris         #+#    #+#                 */
/*   Updated: 2020/08/31 20:19:58 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_usage(void)
{
	ft_putendl("Usage: ./corewar [-dump N | -n (1-MAX_PLAYERS)] "
		"<champion1.cor> <...>");
}

int			main(int argc, char **argv)
{
	//t_champion	champions[MAX_PLAYERS];
	t_arena		arena;

	ft_bzero(&arena, sizeof(arena));
	check_args(argc, argv, &arena);
	check_champions(arena.champions, arena.champion_count);
	start_arena(&arena);
	visual_main(&arena);
	return (EXIT_SUCCESS);
}
