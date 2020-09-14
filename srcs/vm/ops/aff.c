/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 18:05:23 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/14 15:57:30 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	only counted as OK by tester if it doesn't do anything
*/

void	inst_aff(t_arena *arena, t_cursor *cursor)
{
	if (arena == NULL || cursor == NULL)
		return ;
	if (arena->dump_flag == -1)
		ft_printf("%c", (char)cursor->args[0].value);
}
