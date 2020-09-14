/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ld.c                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/17 20:01:26 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/14 15:56:07 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	LD
**	Loads value of 1st argument into register of 2nd argument
**	t_dir size of LD = 4
*/

void		inst_ld(t_arena *arena, t_cursor *cursor)
{
	if (arena == NULL || cursor == NULL)
		return ;
	cursor->registries[cursor->args[1].value - 1] = cursor->args[0].value;
	if (cursor->args[0].value == 0)
		cursor->carry = 1;
	else
		cursor->carry = 0;
}
