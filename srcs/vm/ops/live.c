/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 10:00:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/15 21:40:37 by wmisiedj      ########   odam.nl         */
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

void				inst_live(t_arena *arena, t_cursor *cursor)
{
	t_champion *champ;

	arena->live_count += 1;
	champ = NULL;
	if (cursor->args[0].value == cursor->registries[0])
	{
		champ = find_player_id(arena, cursor->registries[0] * -1);
		if (champ != NULL)
			arena->winner = champ;
		if (champ != NULL && !arena->visualizer.enabled &&
		arena->dump_flag == -1)
			ft_printf("A process shows that player %d (%s) is alive\n",
			arena->winner->id, arena->winner->champ.name);
	}
	cursor->last_alive = arena->cycles_total;
	return ;
}
