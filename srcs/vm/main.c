/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:37:52 by joris         #+#    #+#                 */
/*   Updated: 2020/07/31 14:51:21 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int argc, char **argv)
{
	//t_champion	champions[MAX_PLAYERS];
	t_arena		arena;

	ft_bzero(&arena, sizeof(arena));
	check_args(argc, argv, &arena);
	check_champions(arena.champions, arena.champion_count);
	start_arena(&arena);
	return (OK);
}
