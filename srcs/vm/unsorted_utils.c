/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   unsorted_utils.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 02:05:48 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/15 22:36:43 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	breakpoint_flag(int index, int argc, char **argv, t_arena *arena)
{
	index++;
	if (index < argc)
		arena->visualizer.breakpoint = ft_atoi(argv[index]);
	else
	{
		printf("NO MORE SHIT.\n");
		vm_error(kErrParams);
	}
	return (index);
}

int			check_visual_flags(t_arena *arena, int index, int argc, char **argv)
{
	if (ft_strcmp(argv[index], "-v") == 0)
		arena->visualizer.enabled = true;
	if (ft_strcmp(argv[index], "-f") == 0)
		arena->visualizer.framemode = true;
	if (ft_strcmp(argv[index], "-b") == 0)
		index = breakpoint_flag(index, argc, argv, arena);
	return (index);
}
