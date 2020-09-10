/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 10:00:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/10 20:22:43 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_champion	*find_player_id(t_arena *arena, int id)
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

void	inst_live(t_arena *arena, t_cursor *cursor)
{
	arena->live_count += 1;
	if (cursor->args[0].value == cursor->registries[0])
	{
		arena->winner = find_player_id(arena, cursor->registries[0] * -1);
		if (!arena->visu_flag)
			ft_printf("A process shows that player %d (%s) is alive\n", arena->winner->id, arena->winner->champ.name);
	}
	cursor->last_alive = arena->cycle_count;
	return;
}
