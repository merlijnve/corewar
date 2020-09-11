/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 20:54:02 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/11 13:20:58 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/time.h>
#include <ncurses.h>

#include "vm.h"

static void	show_arena(WINDOW *win, t_arena *arena)
{
	int i;
	int j;
	t_champion *champion;

	i = 0;
	j = 0;
	champion = NULL;
	wmove(win, 0, 0);
	while (i < MEM_SIZE)
	{
		while (j < VISUAL_WIDTH && (i + j) < MEM_SIZE)
		{
			if (arena->cells[i + j].cursor == NULL)
				wattrset(win, COLOR_PAIR(6));
			else
			{
				champion = champion_find_id(arena, arena->cells[i + j].cursor->registries[0] * -1);
				if (champion != NULL)
					wattrset(win, COLOR_PAIR(champion->id));
				else
					wattrset(win, COLOR_PAIR(5));
			}
			wprintw(win, "%02X", (unsigned char)(arena->mem)[i + j]);
			wattrset(win, COLOR_PAIR(6));
			wprintw(win, " ");
			j++;
		}
		j = 0;
		i += VISUAL_WIDTH;
	}
}

static void	show_players(WINDOW *win, t_arena *arena)
{
	int i;

	i = 0;
	wattrset(win, COLOR_PAIR(5));
	mvwprintw(win, 2, 3, "PLAYERS:");
	while (i < MAX_PLAYERS)
	{
		if (arena->champions[i].id > 0) {
			wattrset(win, COLOR_PAIR(i + 1));
			mvwprintw(win, i + 4, 3, "[%d] %s", arena->champions[i].id, arena->champions[i].champ.name);
		}

		i++;
	}
	attroff(COLOR_PAIR(i + 1));
}

static void	print_registries(WINDOW *win, t_cursor *cursor, int y, int x)
{
	int i;

	i = 0;
	while (i < 16)
	{
		mvwprintw(win, y + i, x, "REG [%d]: %d", i + 1, cursor->registries[i]);
		i++;
	}
}

static void	show_stats(WINDOW *win, t_arena *arena, t_cursor *cursor)
{
	show_players(arena->visualizer.stats, arena);
	wattrset(win, COLOR_PAIR(5));
	mvwprintw(win, 11, 3, "STATS:");
	wattrset(win, COLOR_PAIR(6));
	box(win, 0, 0);
	mvwprintw(win, 13, 3, "Cycles:\t%d", arena->cycle_count);
	mvwprintw(win, 14, 3, "Cursors:\t%d/%d", arena->cursors_active, arena->cursor_count);
	mvwprintw(win, 15, 3, "Death:\t%d/%d",
		arena->cycles_since_check, arena->cycles_to_die);
	mvwprintw(win, 16, 3, "Checks:\t%d/%d", arena->check_count, MAX_CHECKS);
	mvwprintw(win, 17, 3, "Live:\t%d", arena->live_count);
	mvwprintw(win, 18, 3, "Sleep:\t%dµs", arena->visualizer.sleep);
	if (arena->winner != NULL)
	{
		mvwprintw(win, 20, 3, "Winner:");
		mvwprintw(win, 21, 3, "[%d] %s", arena->winner->id, arena->winner->champ.name);

	}
	if (cursor != NULL)
	{
		mvwprintw(win, 23, 3, " -- cursor (ID: %d) -- ", cursor->id);
		mvwprintw(win, 24, 3, "opcode:\t%d", cursor->opcode);
		mvwprintw(win, 25, 3, "timeout:\t%d", cursor->timeout);
		mvwprintw(win, 26, 3, "pos:\t%d", get_pos(cursor->pos, 0));
		print_registries(win, cursor, 28, 3);
	}
}

void		visual_update(t_arena *arena, t_cursor *cursor)
{
	if (arena->visualizer.arena == NULL)
		arena->visualizer.arena = newwin(64, VISUAL_WIDTH, 0, 0);
	if (arena->visualizer.stats != NULL)
		delwin(arena->visualizer.stats);
	
	arena->visualizer.stats = newwin(64, 32, 0, VISUAL_WIDTH);

	show_arena(arena->visualizer.arena, arena);
	show_stats(arena->visualizer.stats, arena, cursor);

	wrefresh(arena->visualizer.arena);
	wrefresh(arena->visualizer.stats);

	if (arena->visualizer.sleep > 0) {
		usleep(arena->visualizer.sleep);
	}
}
