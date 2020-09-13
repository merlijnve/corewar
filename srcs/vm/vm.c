/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 13:34:50 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/13 19:03:49 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static t_champion	*highest_player_id(t_arena *arena_s)
{
	int			i;
	t_champion	*winner;

	winner = &arena_s->champions[0];
	i = 1;
	while (i < MAX_PLAYERS)
	{
		if (arena_s->champions[i].id != 0 && arena_s->champions[i].id >
		winner->id)
			winner = &arena_s->champions[i];
		i++;
	}
	return (winner);
}

static void			vm_introduce_champions(t_arena *arena_s)
{
	int			i;
	t_champion	*champion;

	i = 0;
	champion = NULL;
	ft_printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS)
	{
		champion = &(arena_s->champions[i]);
		if (champion->id > 0)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n",
			champion->id, champion->champ.size, champion->champ.name,
			champion->champ.comment);
		i++;
	}
}

static void			vm_place_champions(t_arena *arena_s)
{
	int offset;
	int i;
	int x;

	i = 0;
	x = 0;
	offset = MEM_SIZE / arena_s->champion_count;
	while (i < MAX_PLAYERS)
	{
		if (arena_s->champions[i].id > 0)
		{
			arena_s->champions[i].mem_index = x * offset;
			ft_memcpy(
					arena_s->mem + arena_s->champions[i].mem_index,
					((const void *)(arena_s->champions[i].champ.exec_code)),
					CHAMP_MAX_SIZE);
			x++;
		}
		i++;
	}
}

static int			vm_init_cursors(t_arena *arena_s)
{
	int			i;
	t_cursor	*start;
	t_cursor	*current;

	i = 0;
	start = NULL;
	current = NULL;
	while (i < MAX_PLAYERS)
	{
		if (arena_s->champions[i].id > 0)
		{
			current = cursor_add(arena_s, NULL);
			if (current == NULL)
				return (kErrOther);
			cursor_setpos(arena_s, current, arena_s->champions[i].mem_index);
			current->timeout = -1;
			current->registries[0] = -arena_s->champions[i].id;
		}
		++i;
	}
	return (kOk);
}

void				vm_start(t_arena *arena_s)
{
	arena_s->cycle_count = 0;
	arena_s->winner = highest_player_id(arena_s);
	arena_s->cycles_to_die = CYCLE_TO_DIE;
	arena_s->visualizer.sleep = VISUAL_TIMEOUT;
	vm_place_champions(arena_s);
	if (vm_init_cursors(arena_s) != kOk)
		; // TODO: Error message?
	vm_introduce_champions(arena_s);
	if (arena_s->visualizer.enabled == true)
		visual_start(arena_s);
	while (vm_run_cycle(arena_s))
	{
		arena_s->cycle_count++;
		if (DEBUG_MAX_CYCLES && arena_s->cycle_count > DEBUG_MAX_CYCLES)
			break ;
		if (arena_s->dump_flag != -1 &&
		arena_s->dump_flag <= arena_s->cycle_count)
			dump(arena_s->mem);
	}
	if (arena_s->visualizer.enabled)
		visual_clear(arena_s);
	ft_printf("Contestant %d, \"%s\", has won !\n",
	arena_s->winner->id, arena_s->winner->champ.name);
}
