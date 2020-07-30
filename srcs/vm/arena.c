/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arena.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedjan <wmisiedjan@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 16:16:33 by wmisiedjan    #+#    #+#                 */
/*   Updated: 2020/07/29 21:08:28 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

static void        place_champions(t_arena *arena_s)
{
    int offset;
    int i;

    i = 0;
    offset = MEM_SIZE / arena_s->champion_count;

    while (i < arena_s->champion_count)
    {
        ft_memcpy(
            arena_s->mem + (i * offset),
            arena_s->champions[i].exec_code,
            CHAMP_FILESIZE
        );
        i++;
    }
}

void        start_arena(t_arena *arena_s)
{
    // Let's start the arena.

    // First, let's place the champions.
    place_champions(arena_s); 

    debug_print_map(arena_s);
}