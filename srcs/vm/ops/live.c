/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 10:00:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/10 14:28:54 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// TODO: Check if this is absolutely everything
void	inst_live(t_arena *arena, t_cursor *cursor)
{
	int player;

	if (arena == NULL || cursor == NULL)
		return;
	player = cursor->registries[0];
	arena->live_count += 1;

	// TODO: check if player exist
	if (true)
	{
		// TODO: find player for id
		arena->winner = &arena->champions[0];
	}
	cursor->last_alive = arena->cycle_count;

	return;
}

