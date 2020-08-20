/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arena.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedjan <wmisiedjan@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 16:16:33 by wmisiedjan    #+#    #+#                 */
/*   Updated: 2020/08/01 16:17:15 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

static void        place_champions(t_arena *arena_s)
{
    int offset;
    int i;

    i = 0;
    offset = MEM_SIZE / arena_s->champion_count;

    debug_printf("Placing champions in memory...\n\n");

    while (i < arena_s->champion_count)
    {
        ft_memcpy(
            arena_s->mem + (i * offset),
            ((const void *)(arena_s->champions[i].champ.exec_code)),
            CHAMP_MAX_SIZE
        );
        i++;
    }
}

void        start_arena(t_arena *arena_s)
{
    debug_printf("Starting arena... \n");

    // First, let's place the champions.
    place_champions(arena_s); 

    debug_print_map(arena_s);

    debug_printf("\nPlacing cursors...\n");
}