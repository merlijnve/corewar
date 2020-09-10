/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 20:12:03 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/10 14:02:42 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <utmp.h>
#include <ncurses.h>

#include "vm.h"

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

void		visual_clear(t_arena *arena_s)
{
	wclear(arena_s->win);
	wclear(arena_s->stats);
	refresh();
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
