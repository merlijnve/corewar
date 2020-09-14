/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   champions.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 21:39:36 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/14 15:48:40 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_champion	*champion_find_id(t_arena *arena, int id)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (arena->champions[i].id == id)
			return (&arena->champions[i]);
		i++;
	}
	return (NULL);
}

void		set_champ_zero(t_arena *arena, int i)
{
	arena->champions[i].id = 0;
	arena->champions[i].fd = 0;
	arena->champions[i].argv_index = 0;
	arena->champions[i].file_name = NULL;
}

void		set_champ_name(t_arena *arena, char **argv)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (arena->champions[i].argv_index > 0)
			arena->champions[i].file_name =
			argv[arena->champions[i].argv_index];
		i++;
	}
}
