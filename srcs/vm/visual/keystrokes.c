/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystrokes.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 15:39:12 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/10 17:10:22 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	change_speed(int key, t_arena *arena)
{
	if (key == KEY_UP && arena->speed < 1000)
		arena->speed += 50;
	if (key == KEY_DOWN && arena->speed > 50)
		arena->speed -= 50;
	if (key == KEY_SPACE)
	{
		while (1)
		{
			key = wgetch(arena->win);
			if (key == KEY_SPACE)
				break ;
		}
	}
}

void		visual_readkey(t_arena *arena)
{
	int	c;

	keypad(arena->win, true);
	nodelay(arena->win, true);
	c = wgetch(arena->win);
	change_speed(c, arena);
	if (c == KEY_ESC)
		exit(EXIT_SUCCESS);
}
