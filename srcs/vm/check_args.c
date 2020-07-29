/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 18:53:34 by joris         #+#    #+#                 */
/*   Updated: 2020/07/29 15:39:31 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	output_error(int error_number, char *arg)
{
	if (error_number == -2)
		ft_putendl("Usage: ./corewar [-dump N | -n (1-MAX_PLAYERS)] "
		"<champion1.cor> <...>");
	if (error_number == -3)
		ft_printf("Can't read source file %s\n", arg);
	if (error_number == -4)
		ft_putendl("Too many champions");
	exit(0);
}

/*
**	Simple check and add of the -dump flag
*/

static int	dump_flag(int index, int argc, char **argv, t_arena *arena)
{
	index++;
	if (index < argc)
		arena->dump_flag = ft_atoi(argv[index]); // This can mess up the player count because it takes everything as a player number
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

static int	number_champ(int index, int argc, char **argv, t_arena *arena)
{
	int		player_n;

	if (index > argc - 1)
		output_error(-2, NULL);
	player_n = ft_atoi(argv[index]); // This can mess up the player count because it takes everything as a player number
	if (player_n > MAX_PLAYERS || player_n <= 0 ||
	arena->n_flag || arena->champions[player_n - 1].fd != 0)
		output_error(-2, NULL);
	index++;
	if (ft_strstr(argv[index], ".cor") != NULL)
	{
		arena->champions[player_n - 1].fd = open(argv[index], O_RDONLY);
		arena->champions[player_n - 1].argv_index = index;
		if (arena->champions[player_n - 1].fd < 0)
			output_error(-3, argv[index]);
		arena->champion_count++;
		if (arena->champion_count > MAX_PLAYERS)
			output_error(-4, NULL);
	}
	else
		output_error(-2, NULL); // Isn't necessary but keeps the user on point, no champion after -n flag
	return (index);
}

/*
**	Extracts data from the given arguments or stops on a certain error
*/

static void	loop_args(int argc, char **argv, t_arena *arena)
{
	int		index;

	index = 1;
	while (index < argc)
	{
		if (ft_strstr(argv[index], ".cor") != NULL)
		{
			arena->champion_count++;
			if (arena->champion_count > MAX_PLAYERS)
				output_error(-4, NULL);
			arena->champions[arena->champion_count - 1].argv_index = index;
		}
		if (ft_strcmp(argv[index], "-n") == OK)
		{
			index++;
			index = number_champ(index, argc, argv, arena);
		}
		if (ft_strcmp(argv[index], "-dump") == OK)
			index = dump_flag(index, argc, argv, arena);
		index++;
	}

}

void		check_args(int argc, char **argv, t_arena *arena)
{
	int		index_fd;
	int		c;

	index_fd = 0;
	c = 0;
	loop_args(argc, argv, arena);
	if (arena->champion_count == 0 || arena->n_flag > arena->champion_count)
		output_error(-2, NULL);
	while (arena->champion_count > index_fd)
	{
		if (arena->champions[index_fd].fd == 0)
		{
			arena->champions[index_fd].fd =
			open(argv[arena->champions[index_fd].argv_index], O_RDONLY);
			if (arena->champions[index_fd].fd < 0)
				output_error(-3, argv[arena->champions[index_fd].argv_index]);
		}
		index_fd++;
	}
	while (c < arena->champion_count)
	{
		arena->champions[c].file_name = argv[arena->champions[c].argv_index];
		c++;
	}
}
