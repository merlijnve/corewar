/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   visual_main.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/31 20:12:03 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/08/31 20:30:54 by mvan-eng      ########   odam.nl         */
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
	while (i < 1)
	{
		while (j < 64)
		{
			waddch(win, mem[i + j] + 65);
			j++;
		}
		i++;
	}
}

void		visual_main(t_arena *arena)
{
	WINDOW *win;

	win = initscr();
	noecho();
	curs_set(FALSE);

	//waddstr(win, "test");
	show_arena(win, arena->mem);
	wrefresh(win);
	sleep(2);
	while (1)
		;
}
