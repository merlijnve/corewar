/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 18:53:34 by joris         #+#    #+#                 */
/*   Updated: 2020/07/15 20:24:11 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	output_error(int error_number, char *arg)
{
	if (error_number == -2)
		ft_printf("Usage: ./corewar [-dump N | -n N] <champion1.cor> <...>\n");
	if (error_number == -3)
		ft_printf("Can't read source file %s\n", arg);
	if (error_number == -4)
		ft_printf("Usage -n: [-n (1-MAX_PLAYERS) <champion.cor>]\n");
	exit(0);
}

/*
**	Simple check and add of the -dump flag
**	error_numbers;
**	-2: Not enough arguments after -dump flag
*/

static void	dump_flag(int index, int argc, char **argv, t_vm *vm_s)
{
	index++;
	if (index < argc)
	{
		vm_s->f_dump = ft_atoi(argv[index]); // This can mess up the player count because it takes everything as a player number
	}
	else
		output_error(-2, NULL);
}

/*
**	Numbers a champ after the use of -n flag,
**	and checks for errors ->
**	error_numbers;
**	-2: Not enough arguments after -n flag
**	-3: Can't open source file
**	-4: Invalid value after -n flag
*/

static int	number_champ(int index, int argc, char **argv, t_vm *vm_s)
{
	int		player_n;

	if (index < argc - 1)
	{
		player_n = ft_atoi(argv[index]); // This can mess up the player count because it takes everything as a player number	
		if (player_n > MAX_PLAYERS || player_n <= 0)
			output_error(-4, NULL);
		index++;
		if (ft_strstr(argv[index], ".cor") != NULL)
		{
			vm_s->champ_fd[player_n - 1][0] = open(argv[index] , O_RDONLY);
			vm_s->champ_fd[player_n - 1][1] = index;
			if (vm_s->champ_fd[player_n - 1] < 0)
				output_error(-3, NULL);
		}
	}
	else
		output_error(-2, NULL);
	return (index);
}

/*
**	Extracts data from the given arguments or stops on a certain error
*/

static int	loop_args(int argc, char **argv, t_vm *vm_s)
{
	int		index;

	index = 1;
	while (index < argc)
	{
		if (ft_strstr(argv[index], ".cor") != NULL)
		{
			vm_s->champ_c++;
			vm_s->champ_fd[vm_s->champ_c][1] = index;
		}
		if (ft_strcmp(argv[index], "-n") == OK)
		{
			index = number_champ(index++, argc, argv, vm_s);
			if (index < 0)
				return (index);
		}
		if (ft_strcmp(argv[index], "-dump") == OK)
			dump_flag(index, argc, argv, vm_s);
		index++;
	}
	return (1); // niet nodig
}

int			check_args(int argc, char **argv, t_vm *vm_s)
{
	int		num;

	num = 0;
	loop_args(argc, argv, vm_s);
	return (OK);
}
