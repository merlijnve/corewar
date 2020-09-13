/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/09 20:54:02 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/13 18:08:26 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <sys/time.h>
#include <ncurses.h>

#include "vm.h"

void		visual_print_arena(WINDOW *win, t_arena *arena)
{
	int i;
	int j;

	i = 0;
	j = 0;
	wmove(win, 0, 0);
	while (i < MEM_SIZE)
	{
		while (j < VISUAL_WIDTH && (i + j) < MEM_SIZE)
		{
			visual_set_cursor_color(win, arena, arena->cells[i + j].cursor);
			wprintw(win, "%02X", (unsigned char)(arena->mem)[i + j]);
			wattrset(win, COLOR_PAIR(6));
			wprintw(win, " ");
			j++;
		}
		j = 0;
		i += VISUAL_WIDTH;
	}
}

void		visual_print_players(WINDOW *win, t_arena *arena)
{
	int i;

	i = 0;
	wattrset(win, COLOR_PAIR(5));
	mvwprintw(win, 2, 3, "PLAYERS:");
	while (i < MAX_PLAYERS)
	{
		if (arena->champions[i].id > 0) {
			wattrset(win, COLOR_PAIR(arena->champions[i].id));
			mvwprintw(win, i + 4, 3, "[%d] %s", arena->champions[i].id, arena->champions[i].champ.name);
			attroff(COLOR_PAIR(arena->champions[i].id));
		}
		i++;
	}
}

static void	visual_print_cursor(WINDOW *win, t_cursor *cursor)
{
	int i;

	i = 0;
	wattrset(win, COLOR_PAIR(5));
	mvwprintw(win, 24, 3, "CURSOR:");
	wattrset(win, COLOR_PAIR(6));
	mvwprintw(win, 26, 3, "operation:\t%s (%d)", is_opcode(cursor->opcode) ?
		get_opinfo(cursor->opcode)->name : "?", cursor->opcode);
	mvwprintw(win, 27, 3, "timeout:\t%d", cursor->timeout);
	mvwprintw(win, 28, 3, "pos:\t\t%d", get_pos(cursor->pos, 0));
	mvwprintw(win, 29, 3, "last alive:\t%d", cursor->last_alive);
	while (i < 16)
	{
		mvwprintw(win, 31 + i, 3, "REG [%d]:\t%d", i + 1, cursor->registries[i]);
		i++;
	}
}

void		visual_print_stats(WINDOW *win, t_arena *arena, t_cursor *cursor)
{
	if (arena->winner != NULL)
	{
		wattrset(win, COLOR_PAIR(5));
		mvwprintw(win, 11, 3, "WINNER:");
		wattrset(win, COLOR_PAIR(arena->winner->id));
		mvwprintw(win, 13, 3, "[%d] %s", arena->winner->id, arena->winner->champ.name);
	}
	wattrset(win, COLOR_PAIR(5));
	mvwprintw(win, 15, 3, "STATS:");
	wattrset(win, COLOR_PAIR(6));
	box(win, 0, 0);
	mvwprintw(win, 17, 3, "Cycles:\t%d", arena->cycle_count);
	mvwprintw(win, 18, 3, "Cursors:\t%d/%d", arena->cursors_active, arena->cursor_count);
	mvwprintw(win, 19, 3, "Death:\t%d/%d",
		arena->cycles_since_check, arena->cycles_to_die);
	mvwprintw(win, 20, 3, "Checks:\t%d/%d", arena->check_count, MAX_CHECKS);
	mvwprintw(win, 21, 3, "Live:\t%d", arena->live_count);
	mvwprintw(win, 22, 3, "Sleep:\t%dµs", arena->visualizer.sleep);
	if (cursor != NULL)
		visual_print_cursor(win, cursor);
}

void		visual_update(t_arena *arena, t_cursor *cursor)
{
	if (arena->visualizer.arena == NULL)
		arena->visualizer.arena = newwin(64, VISUAL_WIDTH, 0, 0);
	if (arena->visualizer.stats == NULL)
		arena->visualizer.stats = newwin(64, 32, 0, VISUAL_WIDTH);
	visual_print_arena(arena->visualizer.arena, arena);
	werase(arena->visualizer.stats);
	visual_print_players(arena->visualizer.stats, arena);
	visual_print_stats(arena->visualizer.stats, arena, cursor);
	wrefresh(arena->visualizer.arena);
	wrefresh(arena->visualizer.stats);
	if (arena->visualizer.sleep > 0) {
		usleep(arena->visualizer.sleep);
	}
}
