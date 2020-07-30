/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:37:52 by joris         #+#    #+#                 */
/*   Updated: 2020/07/30 13:48:31 by merlijn       ########   odam.nl         */
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
	return (OK);
}
