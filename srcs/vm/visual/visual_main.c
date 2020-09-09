/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 20:12:03 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/09 15:42:32 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <utmp.h>
#include <ncurses.h>

#include "vm.h"

static void	show_arena(WINDOW *win, t_arena *arena)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < MEM_SIZE)
	{
		while (j < VISUAL_WIDTH && (i + j) < MEM_SIZE)
		{
			wattrset(win, COLOR_PAIR(arena->cells[i + j].taken ? 3 : 6));
			wprintw(win, "%02X", (unsigned char)(arena->mem)[i + j]);
			attroff(COLOR_PAIR(arena->cells[i + j].taken ? 3 : 6));
			wprintw(win, " ");
			j++;
		}
		j = 0;
		i += VISUAL_WIDTH;
	}
}

static void	show_players(WINDOW *win, t_champion *champion, int n_champs)
{
	int i;

	i = 0;
	wattrset(win, COLOR_PAIR(5));
	mvwprintw(win, 2, 3, "PLAYERS:");
	while (i < n_champs)
	{
		wattrset(win, COLOR_PAIR(i + 1));
		mvwprintw(win, i + 4, 3, "[%d] %s", i + 1, champion->champ.name);
		i++;
	}
	attroff(COLOR_PAIR(i + 1));
}

static void print_registeries(WINDOW *win, t_cursor *cursor, int y, int x)
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
	wattrset(win, COLOR_PAIR(5));
	mvwprintw(win, 11, 3, "STATS:");
	wattrset(win, COLOR_PAIR(6));
	box(win, 0, 0);
	mvwprintw(win, 13, 3, "Total cycles:\t%d", arena->cycle_count);
	mvwprintw(win, 14, 3, "Total cursors:\t%d", arena->cursor_count);
	mvwprintw(win, 15, 3, "Cycles to die:\t%d/%d", arena->cycles_since_check, arena->cycles_to_die);
	mvwprintw(win, 16, 3, "Checks:\t%d/%d", arena->check_count, MAX_CHECKS);
	mvwprintw(win, 17, 3, "Live:\t%d", arena->live_count);
	mvwprintw(win, 18, 3, "Speed:\t%d", arena->speed);
	if (arena->winner != NULL)
		mvwprintw(win, 19, 3, "winner_id:\t%d", arena->winner->id);
	if (cursor != NULL) {
		mvwprintw(win, 21, 3, " -- cursor (ID: %d) -- ", cursor->id);
		mvwprintw(win, 22, 3, "opcode:\t%d", cursor->opcode);
		mvwprintw(win, 23, 3, "timeout:\t%d", cursor->timeout);
		mvwprintw(win, 24, 3, "pos:\t%d", get_pos(cursor->pos, 0));
		print_registeries(win, cursor, 27, 3);
		show_players(arena->stats, arena->champions, arena->champion_count);
	}
}

static void	show_color(void)
{
	start_color();
	init_pair(1, COLOR_CYAN, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(5, COLOR_BLACK, COLOR_WHITE);
	init_pair(6, COLOR_WHITE, COLOR_BLACK);
}

void		update_window(t_arena *arena, t_cursor *cursor)
{
	if (arena->visu_flag == true)
	{
		if (arena->win != NULL)
			delwin(arena->win);
		if (arena->stats != NULL)
			delwin(arena->stats);
		arena->win = newwin(64, VISUAL_WIDTH, 0, 0);
		arena->stats = newwin(64, 32, 0, VISUAL_WIDTH);
		show_arena(arena->win, arena);
		show_stats(arena->stats, arena, cursor);
		wrefresh(arena->win);
		wrefresh(arena->stats);
		usleep(1000000 / arena->speed);
	}
}

void		open_stats()
{
	int master;
	int slave;
}

void		visual_main(t_arena *arena)
{
	initscr();
	noecho();
	cbreak();
	curs_set(FALSE);
	show_color();
	open_stats();
	update_window(arena, NULL);
}
