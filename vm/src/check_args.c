/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 18:53:34 by joris         #+#    #+#                 */
/*   Updated: 2020/07/14 20:28:21 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
*	error numbers;
*	-2: not enough args after -n flag 
*/

static int	number_champ(int index, int argc, char **argv, t_vm *vm_s)
{
	int		player_n;

	if (index < argc - 1)
	{
		player_n = ft_atoi(argv[index]); // This can mess up the player count because it takes everything as a player number	
		index++;
		if (ft_strstr(argv[index], ".cor") != NULL)
		{
			vm_s->champ_fd[player_n - 1] = open(argv[index] , O_RDONLY);
			if (vm_s->champ_fd[player_n - 1] < 0)
				return (-3);
		}
	}
	else
		return (-2);
	return (index);
}

/*
*	if index is returned it is a error number,
*	look at above function comment for number explanation 
*/

static int	loop_args(int argc, char **argv, t_vm *vm_s)
{
	int		index;

	index = 1;
	while (index < argc)
	{
		if (ft_strstr(argv[index], ".cor") != NULL)
			vm_s->champ_c++;
		if (ft_strcmp(argv[index], "-n") == OK)
		{
			index = number_champ(index++, argc, argv, vm_s);
			if (index < 0)
				return (index);
		}
		index++;
	}

}

int			check_args(int argc, char **argv, t_vm *vm_s)
{
	int		num;

	num = 0;
	loop_args(argc, argv, vm_s);
	return (OK);
}