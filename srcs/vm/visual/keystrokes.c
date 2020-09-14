/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystrokes.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 15:39:12 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/14 13:55:46 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	change_speed(int key, t_arena *arena)
{
	if (arena->visualizer.framemode)
	{
		while (arena->visualizer.framemode)
		{
			key = wgetch(arena->visualizer.arena);
			if (key == KEY_RIGHT)
				return ;
			if (key == KEY_SPACE)
				arena->visualizer.framemode = !arena->visualizer.framemode;
		}
		return ;
	}
	if (key == KEY_UP && arena->visualizer.sleep < INT32_MAX)
		arena->visualizer.sleep += 100;
	if (key == KEY_DOWN && arena->visualizer.sleep >= 100)
		arena->visualizer.sleep -= 100;
	if (key == KEY_RIGHT && arena->visualizer.sleep < INT32_MAX)
		arena->visualizer.sleep += 1;
	if (key == KEY_LEFT && arena->visualizer.sleep >= 1)
		arena->visualizer.sleep -= 1;
	if (key == KEY_SPACE)
		arena->visualizer.framemode = !arena->visualizer.framemode;
}

void		visual_readkey(t_arena *arena)
{
	int	c;

	keypad(arena->visualizer.arena, true);
	nodelay(arena->visualizer.arena, true);
	c = wgetch(arena->visualizer.arena);
	change_speed(c, arena);
	if (c == KEY_ESC)
		exit(EXIT_SUCCESS);
}
