/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 10:00:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/10 15:55:09 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_champion	*find_player_id(t_arena *arena, int id)
{
	int		i;

	i = 0;
	while (i < MAX_CHAMPS)
	{
		if (arena->champions[i].id == id)
			return (&arena->champions[i]);
		i++;
	}
	return (NULL);
}

// TODO: Check if this is absolutely everything
void	inst_live(t_arena *arena, t_cursor *cursor)
{
	t_champion *player;

	arena->live_count += 1;
	player = find_player_id(arena, cursor->registries[0]);

	if (player < MAX_CHAMPS && player > -1)
	{

		arena->winner = &arena->champions[0];
	}
	cursor->last_alive = arena->cycle_count;

	return;
}

