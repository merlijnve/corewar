/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arena.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedjan <wmisiedjan@student.codam.nl      +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 16:16:33 by wmisiedjan    #+#    #+#                 */
/*   Updated: 2020/07/31 17:19:54 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

static void        place_champions(t_arena *arena_s)
{
    int offset;
    int i;

    i = 0;
    offset = MEM_SIZE / arena_s->champion_count;

    printf_debug("Placing champions in memory...\n");

    while (i < arena_s->champion_count)
    {
        ft_memcpy(
            arena_s->mem + (i * offset),
            (const void *)(arena_s->champions[i].champ.exec_code)[i],
            CHAMP_FILESIZE
        );
        i++;
    }
}

void        start_arena(t_arena *arena_s)
{
    printf_debug("Starting arena... \n");

    // First, let's place the champions.
    place_champions(arena_s); 

    // debug_print_map(arena_s);
}