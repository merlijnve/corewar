/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 18:05:23 by merlijn       #+#    #+#                 */
/*   Updated: 2020/08/19 18:15:28 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		check_aff_argument_types(t_argument *args)
{
	if (args[0].type != ARG_TYPE_REG
	|| args[1].type != ARG_TYPE_NONE
	|| args[2].type != ARG_TYPE_NONE)
		return (kError);
	return (kOk);
}

void	inst_aff(t_arena *arena, t_cursor *cursor)
{
	int arg1;

	get_argument_types(arena->mem, cursor);
	if (check_aff_argument_types(cursor->args) == kError)
		return ;
	arg1 = arena->mem[get_pos(cursor->pos, 2)];
	if (is_registry(arg1))
		ft_putchar((char)cursor->registries[arg1 - 1]);
}
