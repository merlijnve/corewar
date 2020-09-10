/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   live.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/06 10:00:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/10 13:17:21 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

// TODO: Check if this is absolutely everything
void	inst_live(t_arena *arena, t_cursor *cursor)
{
	int champ;
	int	t_dir_size;

	t_dir_size = 0; //Need fix, get_arguments.c is deleted
	arena->live_count += 1;
	champ = dir_arg(arena->mem, cursor->pos, t_dir_size);
	champ = champ * -1;
	if (champ < MAX_CHAMPS && champ > -1 && arena->champions[champ - 1])
	{
		// TODO: find player for id
		arena->winner = &arena->champions[0];
	}
	cursor->last_alive = arena->cycle_count;

	return;
}

