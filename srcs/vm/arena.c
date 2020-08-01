/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arena.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedjan <wmisiedjan@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 16:16:33 by wmisiedjan    #+#    #+#                 */
/*   Updated: 2020/08/01 21:14:12 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

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
 * Check if we can kill cursors
 */
static void check_cursors(t_arena *arena_s)
{
    t_cursor *current;

    current = arena_s->cursors;
    while (current)
    {
        // TODO: Add kill logic. 
        debug_printf("[Cursor Turn] Cursor ID %d - Pos: %d", current->id, current->pos);
        current = current->next;
    }
    arena_s->check_count++;
}

static void start_loop(t_arena *arena_s)
{
    while (arena_s->cursors)
    {
        if (arena_s->cycles_to_die > 0 && !arena_s->check_count) {
            // CHEK ONCE in cycles to die.
            check_cursors(arena_s);
        } else if (arena_s->cycles_to_die <= 0) {
            // Check every cycle
            check_cursors(arena_s);
        }
        arena_s->cycles_count++;
        if (CYCLE_TIMEOUT)
            sleep(CYCLE_TIMEOUT);
    }
}

void        init_arena(t_arena *arena_s)
{
    arena_s->last_alive = 0; // TODO: Highest player id.
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
}