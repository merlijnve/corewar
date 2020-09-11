/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 18:53:34 by joris         #+#    #+#                 */
/*   Updated: 2020/09/11 20:30:51 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Simple check and add of the -dump flag
*/

static int	dump_flag(int index, int argc, char **argv, t_arena *arena)
{
	index++;
	if (index < argc)
		arena->dump_flag = ft_atoi(argv[index]);
	else
		vm_error(kErrParams);
	return (index);
}

/*
**	NUMBER_CHAMP
**	Numbers a champ after the use of -n flag,
**	and checks for invalid use of arguments
**
**	NOTE:
**	THE NEXT ARGUMENT'S ASCII VALUE WILL BE TAKEN AS PLAYER NUMBER,
**	this behavior corresponds to the original Corewar VM
*/

static int	number_champ(int index, int argc, char **argv, t_arena *arena)
{
	int		player_n;

	if (index >= argc - 1)
		vm_error(kErrParams);
	player_n = ft_atoi(argv[index]);
	if (player_n > MAX_PLAYERS || player_n <= 0 ||
	arena->n_flag || arena->champions[player_n - 1].fd != 0)
	{
		debug_printf("TESTING... %d\n", player_n);
		vm_error(kErrParams);
	}
	index++;
	if (ft_strstr(argv[index], ".cor") != NULL)
	{
		arena->champions[player_n - 1].fd = open(argv[index], O_RDONLY);
		arena->champions[player_n - 1].argv_index = index;
		if (arena->champions[player_n - 1].fd < 0)
			vm_error(kErrFile, argv[index]);
		arena->champion_count++;
		if (arena->champion_count > MAX_PLAYERS)
			vm_error(kErrTooManyChamps, NULL);
	}
	else
		vm_error(kErrParams);
	return (index);
}

/*
**	LOOP_ARGS
**	Extracts data from the given arguments
**	Checks invalid use of arguments
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
				vm_error(kErrTooManyChamps);
			arena->champions[arena->champion_count - 1].argv_index = index;
		}
		if (ft_strcmp(argv[index], "-n") == 0)
		{
			index++;
			index = number_champ(index, argc, argv, arena);
		}
		if (ft_strcmp(argv[index], "-v") == 0)
			arena->visualizer.enabled = true;
		if (ft_strcmp(argv[index], "-dump") == 0 || ft_strcmp(argv[index], "-d") == 0)
			index = dump_flag(index, argc, argv, arena);
		index++;
	}
}

/*
**	CHECK_ARGS
**	Checks for invalid use of arguments
**	Extracts the necessary arguments to asign in the given struct
*/

void		check_args(int argc, char **argv, t_arena *arena)
{
	int		index_fd;
	int		c;

	index_fd = 0;
	c = 0;
	arena->dump_flag = -1;
	loop_args(argc, argv, arena);
	if (arena->champion_count == 0 || arena->n_flag > arena->champion_count)
		vm_error(kErrParams, NULL);
	while (arena->champion_count > index_fd)
	{
		if (arena->champions[index_fd].fd == 0)
		{
			arena->champions[index_fd].fd =
			open(argv[arena->champions[index_fd].argv_index], O_RDONLY);
			if (arena->champions[index_fd].fd < 0)
				vm_error(kErrFile, argv[arena->champions[index_fd].argv_index]);
		}
		index_fd++;
	}
	while (c < arena->champion_count)
	{
		arena->champions[c].file_name = argv[arena->champions[c].argv_index];
		c++;
	}
}
