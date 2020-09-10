/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   keystrokes.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 15:39:12 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/10 14:34:28 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		change_speed(int key, t_arena *arena)
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

void		handle_key(t_arena *arena)
{
	int	c;

	keypad(arena->win, true);
	nodelay(arena->win, true);
	c = wgetch(arena->win);
	change_speed(c, arena);
	if (c == KEY_ESC)
		exit(0);
}
