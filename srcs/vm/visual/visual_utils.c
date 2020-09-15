/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 20:12:03 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/15 01:44:34 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <utmp.h>
#include <ncurses.h>
#include <locale.h>

#include "vm.h"

static void	show_color(void)
{
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_CYAN);
	init_pair(2, COLOR_WHITE, COLOR_GREEN);
	init_pair(3, COLOR_WHITE, COLOR_RED);
	init_pair(4, COLOR_WHITE, COLOR_MAGENTA);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
}

void		visual_clear(t_arena *arena_s)
{
	wclear(arena_s->visualizer.arena);
	wclear(arena_s->visualizer.stats);
	refresh();
}

bool		visual_should_update(t_arena *arena)
{
	struct timeval	tv;
	double			time_ms;

	if (!arena->visualizer.enabled)
		return (false);
	gettimeofday(&tv, NULL);
	time_ms = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000;
	if (time_ms - arena->visualizer.updated_ms > 1000 / VISUAL_FPS)
	{
		arena->visualizer.updated_ms = time_ms;
		return (true);
	}
	return (false);
}

void		visual_set_cursor_color(WINDOW *win, t_arena *arena,
t_cursor *cursor)
{
	t_champion *champion;

	champion = NULL;
	if (cursor == NULL)
		wattrset(win, COLOR_PAIR(6));
	else
	{
		champion = champion_find_id(arena, cursor->registries[0] * -1);
		if (champion != NULL)
			wattrset(win, COLOR_PAIR(champion->id));
		else
			wattrset(win, COLOR_PAIR(5));
	}
}

void		visual_start(t_arena *arena)
{
	initscr();
	noecho();
	cbreak();
	curs_set(FALSE);
	show_color();
	visual_update(arena, NULL);
}
