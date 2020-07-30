/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:37:52 by joris         #+#    #+#                 */
/*   Updated: 2020/07/29 20:31:39 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int argc, char **argv)
{
	t_arena		arena_s;
	t_champion	champions[MAX_PLAYERS];

	ft_bzero(&arena_s, sizeof(arena_s));

	check_args(argc, argv, &arena_s);

	start_arena(&arena_s);
	return (OK);
}
