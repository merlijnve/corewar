/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cycle.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 13:46:22 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/14 14:21:33 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		vm_cursor_alive(t_arena *arena_s)
{
    t_cursor	*current;
	t_cursor	*tmp;
    int      	last_cycle;

    current = arena_s->cursors;
    while (current != NULL)
    {
		last_cycle = arena_s->cycle_count - current->last_alive;
		if (arena_s->cycles_to_die <= 0 || last_cycle >= arena_s->cycles_to_die)
		{
			tmp = current->next;
			cursor_del(arena_s, current->id);
			current = tmp;
		}
		else
		{
			current = current->next;
		}
    }
	return (arena_s->cursors != NULL);
}

static void		vm_run_cursor(t_arena *arena_s, t_cursor *current)
{
	t_enbyte enbyte;

	enbyte = (t_enbyte){kTNone, kTNone, kTNone, kTNone};
	if (is_opcode(current->opcode)) 
	{
		if (get_opinfo(current->opcode)->has_enbyte)
		{
			ft_memcpy(&enbyte, &arena_s->mem[get_pos(current->pos, 1)], sizeof(t_enbyte));
			reverse_eb(&enbyte);
		}
		if (
			(!get_opinfo(current->opcode)->has_enbyte || 
			(get_opinfo(current->opcode)->has_enbyte && is_valid_enbyte(current->opcode, enbyte))) &&
			preload_args(arena_s, current))
		{
			debug_printf("args\n\t%d: %.5d %#.4x \n\t%d: %.5d %#.4x \n\t%d: %.5d %#.4x\n", current->args[0].type, current->args[0].value, current->args[0].value, current->args[1].type, current->args[1].value, current->args[1].value, current->args[2].type, current->args[2].value, current->args[2].value);
			get_op_func(current->opcode)(arena_s, current);
		}
		if (current->jump == 0)
		{
			current->jump = args_length(enbyte, current->opcode);
			if (current->opcode == kInstAff && !is_valid_enbyte(current->opcode, enbyte) && (enbyte.arg1 + enbyte.arg2 + enbyte.arg3 + enbyte.arg4) != 0)
				current->jump -= 8;
		}
	}
	else
		current->jump = 1;
	cursor_setpos(arena_s, current, current->pos + current->jump);
	current->jump = 0;
}

static void		vm_run_cursors(t_arena *arena_s)
{
    t_cursor *current;

    current = arena_s->cursors;
    while (current)
    {
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
        current = current->next;
	}
}

bool			vm_run_cycle(t_arena *arena_s)
{
	vm_run_cursors(arena_s);
	arena_s->cycles_since_check++;
	if (arena_s->cycles_since_check >= arena_s->cycles_to_die ||
		arena_s->cycles_to_die < 0)
	{
		if (arena_s->live_count > NBR_LIVE || arena_s->check_count > MAX_CHECKS)
			arena_s->cycles_to_die -= CYCLE_DELTA;
		if (arena_s->live_count < NBR_LIVE)
			arena_s->check_count++;
		if (arena_s->check_count >= MAX_CHECKS)
			arena_s->check_count = 0;
		if (arena_s->live_count >= NBR_LIVE)
			arena_s->live_count = 0;
		vm_cursor_alive(arena_s);
		if (arena_s->cursors == NULL)
			return (false);
		arena_s->cycles_since_check = 0;
	}
	return (true);
}
