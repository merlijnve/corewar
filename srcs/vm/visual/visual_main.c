/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 20:12:03 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/01 16:52:47 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ncurses.h"
#include "vm.h"

static void	show_arena(WINDOW *win, char *mem)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < MEM_SIZE)
	{
		while (j < 62)
		{
			wprintw(win, "%02X%02X ", (unsigned char)mem[i + j], (unsigned char)mem[i + j + 1]);
			j += 2;
		}
		j = 0;
		wprintw(win, "\n");
		i += 64;
	}
	wrefresh(win);
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

static void	show_stats(WINDOW *win, t_arena *arena)
{
	wattrset(win, COLOR_PAIR(5));
	mvwprintw(win, 11, 3, "STATS:");
	wattrset(win, COLOR_PAIR(6));
	box(win, 0, 0);
	mvwprintw(win, 13, 3, "Current cycle:\t%d", arena->current_cycle);
	mvwprintw(win, 14, 3, "Cycles to die:\t%d", arena->cycles_to_die);
	mvwprintw(win, 15, 3, "winner_id:\t%d\tlast_alive:\t%d", arena->winner_id, arena->last_alive);
	show_players(arena->stats, arena->champions, arena->champion_count);
	wrefresh(win);
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

void		update_window(t_arena *arena)
{
	arena->win = newwin(64, 256, 1, 2);
	arena->stats = newwin(62, 95, 2, 159);
	show_arena(arena->win, arena->mem);
	show_stats(arena->stats, arena);
	sleep(1);
}

void		visual_main(t_arena *arena)
{
	initscr();
	noecho();
	cbreak();
	curs_set(FALSE);
	show_color();
	update_window(arena);
}
