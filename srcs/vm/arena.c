/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arena.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedjan <wmisiedjan@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 16:16:33 by wmisiedjan    #+#    #+#                 */
/*   Updated: 2020/09/09 11:56:42 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void         introduce_champions(t_arena *arena_s)
{
    int i;
    t_champion *champion;

    i = 0;
    champion = NULL;
    ft_printf("Introducing contestants...\n");
    while (i < arena_s->champion_count)
    {
        champion = &(arena_s->champions[i]);
        if (arena_s->champions[i].id != -1)
        {
            ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\")\n",
            champion->id, champion->champ.size, champion->champ.name, champion->champ.comment);
        }
        i++;
    }
}

static int        decrease_cycles(t_arena *arena_s)
{
    arena_s->cycles_to_die -= CYCLE_DELTA;
    return (arena_s->cycles_to_die >= 0);
}

static void        place_champions(t_arena *arena_s)
{
    int offset;
    int i;

    i = 0;
    offset = MEM_SIZE / arena_s->champion_count;

    debug_printf("Placing champions in memory...\n\n");

    while (i < arena_s->champion_count)
    {
        arena_s->champions[i].mem_index = i * offset;
		// TODO: write champ id in chack args according to -n flag
		// line below is temp fix to get it running
		arena_s->champions[i].id = i + 1;
        ft_memcpy(
            arena_s->mem + arena_s->champions[i].mem_index,
            ((const void *)(arena_s->champions[i].champ.exec_code)),
            CHAMP_MAX_SIZE
        );
        i++;
    }
}

/**
 * Check if we can kill cursors.
 * Cursor is considered dead, if 
 * it performed operation 'live' 
 * more than cycles_to_die or more cycles ago.
 */
static void vm_cursor_alive(t_arena *arena_s)
{
    t_cursor	*current;
	t_cursor	*tmp;
    int      	last_cycle;

    current = arena_s->cursors;
    debug_printf("Running cursor alive check...\n");
    while (current)
    {
		last_cycle = arena_s->cycle_count - current->last_alive;
		if (last_cycle >= arena_s->cycles_to_die)
		{
			tmp = current->next;
			debug_printf("Deleting cursor: %d\n", current->id);
			cursor_del(&arena_s->cursors, current->id);
			current = tmp;
		}
		else
			current = current->next;
    }
    arena_s->check_count++;
}



static void     vm_run_cursors(t_arena *arena_s)
{
    t_cursor *current;
	t_enbyte enbyte;
    current = arena_s->cursors;

    while (current)
    {
//        debug_printf("Running cursor id: %d...\n", current->id);

		// If -1 or smaller, this is a marker that last cycle there was a move
		// so we now have to write new instruction
		handle_key(arena_s);
		if (current->timeout < 0)
		{
			current->opcode = arena_s->mem[get_pos(current->pos, 0)];
			current->timeout = get_timeout(current->opcode);
		}
		if (current->timeout > 0)
			current->timeout -= 1;
		// read information and validate
		if (current->timeout == 0)
        {
			debug_printf("Reading cursor [%d] @ [%d] op code: %.2d (%s)\n", current->id, get_pos(current->pos, 0), current->opcode, is_opcode(current->opcode) ? get_opinfo(current->opcode)->name : "Invalid Inst");

			// TODO: check if this can be mergered
			if (is_opcode(current->opcode))
			{
				if (get_opinfo(current->opcode)->has_enbyte)
				{
					ft_memcpy(&enbyte, &arena_s->mem[get_pos(current->pos, 1)], sizeof(t_enbyte));
					reverse_eb(&enbyte);
					if (is_valid_enbyte(current->opcode, enbyte))
					{
						if (preload_args(arena_s, current))
						{
							debug_printf("args\n\t%d: %.5d %#.4x \n\t%d: %.5d %#.4x \n\t%d: %.5d %#.4x\n", current->args[0].type, current->args[0].value, current->args[0].value, current->args[1].type, current->args[1].value, current->args[1].value, current->args[2].type, current->args[2].value, current->args[2].value);
							get_op_func(current->opcode)(arena_s, current);
						}
					}
					if (current->jump == 0)
						current->jump = args_length(enbyte, current->opcode);
				}
				else
				{
					if (preload_args(arena_s, current))
					{
						debug_printf("args\n\t%d: %.5d %#.4x \n\t%d: %.5d %#.4x \n\t%d: %.5d %#.4x\n", current->args[0].type, current->args[0].value, current->args[0].value, current->args[1].type, current->args[1].value, current->args[1].value, current->args[2].type, current->args[2].value, current->args[2].value);
						get_op_func(current->opcode)(arena_s, current);
					}
					if (current->jump == 0)
						current->jump = args_length((t_enbyte){}, current->opcode);
				}
			}
			else
				current->jump = 1;
			current->timeout = -1; // after moving always -1
            cursor_setpos(arena_s, current, current->pos + current->jump);
			current->jump = 0;
//			debug_print_mem(arena_s->mem, 64);
		}
        if (DEBUG_VISUAL)
			update_window(arena_s, current);
        current = current->next;
	}
}

bool     vm_cycle(t_arena *arena_s)
{
	// STOP IF ALL CURSORS ARE GONE.
	if (arena_s->cursors == NULL)
		return (false);

	// THE CHECK
	if (arena_s->cycles_since_check >= arena_s->cycles_to_die)
	{
		vm_cursor_alive(arena_s);
		if (arena_s->live_count >= NBR_LIVE)
		{
			decrease_cycles(arena_s);
			arena_s->check_count = 1;
			arena_s->live_count = 0;
		}
		else
		{
			arena_s->check_count += 1;
		}
		if (arena_s->check_count >= MAX_CHECKS)
		{
			decrease_cycles(arena_s);
			arena_s->check_count = 1;
		}
		arena_s->cycles_since_check = 0;
	}
	vm_run_cursors(arena_s);
	arena_s->cycles_since_check++;
	return (true);
}

t_champion *highest_player_id(t_arena *arena_s)
{
    int i;
    t_champion *winner;

    winner = &arena_s->champions[0];
    i = 1;
    while (i < arena_s->champion_count) 
    {
        if (arena_s->champions[i].id != 0 && arena_s->champions[i].id > winner->id)
            winner = &arena_s->champions[i];
        i++;
    }

    return winner;
}

void        init_arena(t_arena *arena_s)
{
	arena_s->cycle_count = 1;
    arena_s->winner = highest_player_id(arena_s);
    arena_s->cycles_to_die = CYCLE_TO_DIE;
	arena_s->speed = 50;
    place_champions(arena_s); 
}

void        start_arena(t_arena *arena_s)
{
    debug_printf("Starting arena... \n");

    // Init
    init_arena(arena_s);
    debug_print_map(arena_s);

    init_cursors(arena_s);
    debug_print_cursors(arena_s->cursors);

    introduce_champions(arena_s);
    debug_printf("\nStarting game processes / game loop?...\n");

    if (DEBUG_VISUAL)
	    visual_main(arena_s);
    while (vm_cycle(arena_s))
    {
        debug_printf(" -- Running cycle '%d' (%d/%d)\n", arena_s->cycle_count, \
            arena_s->cycles_since_check, arena_s->cycles_to_die);
        arena_s->cycle_count++;
        if (DEBUG_MAX_CYCLES && arena_s->cycle_count > DEBUG_MAX_CYCLES)
        {
            debug_printf(" -- DEBUG: Max debug cycle count reached.\n");
            break;
        }
    }
}
