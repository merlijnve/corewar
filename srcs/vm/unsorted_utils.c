/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsorted_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 02:05:48 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/15 02:15:17 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		check_visual_flags(t_arena *arena, char *arg)
{
	if (ft_strcmp(arg, "-v") == 0)
		arena->visualizer.enabled = true;
	if (ft_strcmp(arg, "-f"))
		arena->visualizer.framemode = true;
}
