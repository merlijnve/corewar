/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 18:53:34 by joris         #+#    #+#                 */
/*   Updated: 2020/07/16 14:50:06 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	output_error(int error_number, char *arg)
{
	if (error_number == -2)
		ft_putendl("Usage: ./corewar [-dump N | -n (1-MAX_PLAYERS)] <champion1.cor> <...>");
	if (error_number == -3)
		ft_printf("Can't read source file %s\n", arg);
	if (error_number == -4)
		ft_putendl("Too many champions");
	exit(0);
}

/*
**	Simple check and add of the -dump flag
*/

static int	dump_flag(int index, int argc, char **argv, t_vm *vm_s)
{
	index++;
	if (index < argc)
	{
		vm_s->f_dump = ft_atoi(argv[index]); // This can mess up the player count because it takes everything as a player number
	}
	else
		output_error(-2, NULL);
	return (index);
}

/*
**	Numbers a champ after the use of -n flag,
**	and checks for errors ->
**	error_numbers;
**	-2: Invalid flag use
**	-3: Can't open source file
**	-4: Too many champions
*/

static int	number_champ(int index, int argc, char **argv, t_vm *vm_s)
{
	int		player_n;

	if (index > argc - 1)
		output_error(-2, NULL);
	player_n = ft_atoi(argv[index]); // This can mess up the player count because it takes everything as a player number	
	if (player_n > MAX_PLAYERS || player_n <= 0 || player_n == vm_s->high_n ||
	vm_s->champ_fd[player_n - 1] != 0)
		output_error(-2, NULL);
	if (player_n > vm_s->high_n)
		vm_s->high_n = player_n;
	index++;
	if (ft_strstr(argv[index], ".cor") != NULL)
	{
		vm_s->champ_fd[player_n - 1] = open(argv[index], O_RDONLY);
		vm_s->champ_i[player_n - 1] = index;
		if (vm_s->champ_fd[player_n - 1] < 0)
			output_error(-3, argv[index]);
		vm_s->champ_c++;
		if (vm_s->champ_c > MAX_PLAYERS)
			output_error(-4, NULL);
	}
	else
		output_error(-2, NULL); // Isn't nessecary but keeps the user on point, no champion after -n flag
	return (index);
}

/*
**	Extracts data from the given arguments or stops on a certain error
*/

static void	loop_args(int argc, char **argv, t_vm *vm_s)
{
	int		index;

	index = 1;
	while (index < argc)
	{
		if (ft_strstr(argv[index], ".cor") != NULL)
		{
			vm_s->champ_c++;
			if (vm_s->champ_c > MAX_PLAYERS)
				output_error(-4, NULL);
			vm_s->champ_i[vm_s->champ_c - 1] = index;
		}
		if (ft_strcmp(argv[index], "-n") == OK)
		{
			index++;
			index = number_champ(index, argc, argv, vm_s);
		}
		if (ft_strcmp(argv[index], "-dump") == OK)
			index = dump_flag(index, argc, argv, vm_s);
		index++;
	}
}

void		check_args(int argc, char **argv, t_vm *vm_s)
{
	int		index_fd;

	index_fd = 0;
	loop_args(argc, argv, vm_s);
	if (vm_s->champ_c == 0)
		output_error(-2, NULL);
	if (vm_s->high_n > vm_s->champ_c)
		output_error(-2, NULL);
	while (vm_s->champ_c > index_fd)
	{
		if (vm_s->champ_fd[index_fd] == 0)
		{
			vm_s->champ_fd[index_fd] =
			open(argv[vm_s->champ_i[index_fd]], O_RDONLY);
			if (vm_s->champ_fd[index_fd] < 0)
				output_error(-3, argv[vm_s->champ_i[index_fd]]);
		}
		ft_printf("fd:%i\n", vm_s->champ_fd[index_fd]);
		index_fd++;
	}
}
