/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   aff.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/19 18:05:23 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/10 14:27:10 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	inst_aff(t_arena *arena, t_cursor *cursor)
{
	if (arena == NULL || cursor == NULL)
		return; 
	ft_printf("%c", (char)cursor->args[0].value);
}
