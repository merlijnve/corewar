/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cycle.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 13:46:22 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/17 13:22:33 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		vm_cursor_alive(t_arena *arena_s)
{
	t_cursor	*current;
	t_cursor	*tmp;
	int			lives;

	current = arena_s->cursors;
	while (current != NULL)
	{
		lives = arena_s->cycles_to_die - (arena_s->cycles_total
		- current->last_alive);
		if (arena_s->cycles_to_die <= 0 || lives <= 0)
		{
			tmp = current->next;
			cursor_del(arena_s, current->id);
			current = tmp;
		}
		else
			current = current->next;
	}
	return (arena_s->cursors != NULL);
}

static void		vm_run_cursor(t_arena *arena_s, t_cursor *current)
{
	current->enbyte = (t_enbyte){kTNone, kTNone, kTNone, kTNone};
	if (is_opcode(current->opcode))
	{
		if (get_opinfo(current->opcode)->has_enbyte)
		{
			ft_memcpy(&(current->enbyte),
			&arena_s->mem[get_pos(current->pos, 1)], sizeof(t_enbyte));
			reverse_eb(&(current->enbyte));
		}
		if ((!get_opinfo(current->opcode)->has_enbyte
		|| (get_opinfo(current->opcode)->has_enbyte
				&& is_valid_enbyte(current->opcode, current->enbyte)))
			&& preload_args(arena_s, current))
			get_op_func(current->opcode)(arena_s, current);
		cursor_jump(current, current->enbyte);
	}
	else
		current->jump = 1;
	if (current->opcode == kInstZjmp && current->args[0].value == 0 &&
	current->carry == 1)
		current->jump = 0;
	cursor_setpos(arena_s, current, current->pos + current->jump);
	current->jump = 0;
}

static void		vm_run_cursors(t_arena *arena_s)
{
	t_cursor *current;

	current = arena_s->cursors;
	while (current)
	{
		if (arena_s->visualizer.enabled)
			visual_readkey(arena_s);
		if (current->timeout < 0)
		{
			current->opcode = arena_s->mem[get_pos(current->pos, 0)];
			current->timeout = get_timeout(current->opcode);
		}
		if (current->timeout > 0)
			current->timeout -= 1;
		if (current->timeout == 0)
			vm_run_cursor(arena_s, current);
		if (visual_should_update(arena_s))
			visual_update(arena_s, current);
		ft_bzero(&current->args[0], sizeof(t_argument) * 3);
		current = current->next;
	}
}

bool			vm_run_cycle(t_arena *arena_s)
{
	if (arena_s->cursors == NULL)
		return (false);
	arena_s->cycles_total++;
	arena_s->cycle_count++;
	vm_run_cursors(arena_s);
	if (arena_s->cycle_count >= arena_s->cycles_to_die ||
		arena_s->cycles_to_die <= 0)
	{
		arena_s->check_count++;
		vm_cursor_alive(arena_s);
		if (arena_s->live_count >= NBR_LIVE || arena_s->check_count
		>= MAX_CHECKS)
		{
			arena_s->cycles_to_die -= CYCLE_DELTA;
			arena_s->check_count = 0;
		}
		arena_s->live_count = 0;
		arena_s->cycle_count = 0;
	}
	return (true);
}
