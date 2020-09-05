/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arena.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedjan <wmisiedjan@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 16:16:33 by wmisiedjan    #+#    #+#                 */
/*   Updated: 2020/09/05 17:12:06 by wmisiedj      ########   odam.nl         */
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
    tmp = NULL;
    debug_printf("Running cursor alive check...\n");
    while (current)
    {
		last_cycle = arena_s->cycles_till_check - current->last_alive;
		if (last_cycle >= arena_s->cycles_to_die)
            cursor_del(&arena_s->cursors, current->id);
    }
    arena_s->check_count++;
}

void     vm_run_cursors(t_arena *arena_s)
{
    t_cursor *current;

    current = arena_s->cursors;

    while (current)
    {
        debug_printf("Running cursor id: %d...\n", current->id);
        if (current->timeout == 0)
        {
            // THIS WAS A TEST.
            current->opcode = read_4_bytes(arena_s->mem, get_pos(current->pos, 0));
            debug_printf("Reading cursor op code: %d...\n", current->opcode);
        }
        if (current->timeout > 0)
            current->timeout -= 1;
        else
        {
            // TODO: READ ENCODING BYTE AND ARGUMENTS
            // TODO: Execute operation.
            current->pos = get_pos(current->pos, 1);
            debug_printf("Moving cursor forward.\n");
            // TODO: Maybe remove operation from cursor.
        }
        current = current->next;
        update_window(arena_s, current);
    }
}

bool     vm_cycle(t_arena *arena_s)
{
    // STOP IF ALL CURSORS ARE GONE.
    if (arena_s->cursors == NULL)
        return (false);
    // CHECK IF WE NEED TO REMOVE DEAD CURSORS
    if (arena_s->cycles_till_check >= arena_s->cycles_to_die)
    {
        vm_cursor_alive(arena_s);
        arena_s->cycles_till_check = 0;
        // -- HIER?
           // CHECK IF WE NEED TO DECREASE CYCLES TO DIE
    if (arena_s->live_count >= NBR_LIVE)
    {
        decrease_cycles(arena_s);
        arena_s->live_count = 0;
    }
    }
 
    if (arena_s->live_count == 0 && arena_s->check_count > MAX_CHECKS)
        decrease_cycles(arena_s);
    vm_run_cursors(arena_s);
    arena_s->cycles_till_check++;
    return (true);
}

void        init_arena(t_arena *arena_s)
{
    arena_s->last_alive = arena_s->champion_count - 1;
    arena_s->cycles_to_die = CYCLE_TO_DIE;

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
            arena_s->cycles_till_check, arena_s->cycles_to_die);
        arena_s->cycle_count++;
        if (DEBUG_MAX_CYCLES && arena_s->cycle_count > DEBUG_MAX_CYCLES)
        {
            debug_printf(" -- DEBUG: Max debug cycle count reached.\n");
            break;
        }
    }
}
