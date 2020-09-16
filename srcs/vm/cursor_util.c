/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor_util.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 15:26:56 by joris         #+#    #+#                 */
/*   Updated: 2020/09/16 15:00:48 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		cursor_jump(t_cursor *current, t_enbyte enbyte)
{
	if (current->jump == 0)
	{
		current->jump = args_length(enbyte, current->opcode);
	}
}

void		run_cycle(t_arena *arena)
{
	while (vm_run_cycle(arena))
	{
		if (arena->visualizer.breakpoint == arena->cycles_total &&
			arena->visualizer.enabled == false) {
				arena->visualizer.enabled = true;
				visual_start(arena);
			}
		if (arena->dump_flag == arena->cycles_total)
			dump(arena->mem);
		if (DEBUG_MAX_CYCLES && arena->cycles_total > DEBUG_MAX_CYCLES)
			return ;
	}
}
