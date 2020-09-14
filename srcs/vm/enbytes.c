/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   enbytes.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 20:48:30 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/14 16:24:00 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		reverse_eb(t_enbyte *eb)
{
	t_enbyte bc;

	bc = *eb;
	eb->arg1 = bc.arg4;
	eb->arg2 = bc.arg3;
	eb->arg3 = bc.arg2;
	eb->arg4 = bc.arg1;
}

t_enbyte	*get_enbyte(t_arena *arena, long pos)
{
	t_enbyte *eb;

	eb = (t_enbyte *)&arena->mem[get_pos(pos, 1)];
	return (eb);
}
