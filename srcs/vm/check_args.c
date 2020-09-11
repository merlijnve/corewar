/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 18:53:34 by joris         #+#    #+#                 */
/*   Updated: 2020/09/11 16:22:41 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	Simple check and add of the -dump flag
**	
*/

static int	dump_flag(int index, int argc, char **argv, t_arena *arena)
{
	index++;
	if (index < argc && arena->dump_flag == -1)
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

	index++;
	if (index >= argc - 1)
		vm_error(kErrParams);
	player_n = ft_atoi(argv[index]);
	if (player_n > MAX_PLAYERS || player_n <= 0 ||
	arena->champions[player_n - 1].fd != 0)
		vm_error(kErrParams);
	index++;
	if (ft_strstr(argv[index], ".cor") != NULL)
	{
		arena->champions[player_n - 1].fd = open(argv[index], O_RDONLY);
		arena->champions[player_n - 1].argv_index = index;
		arena->champions[player_n - 1].id = player_n;
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
	int		c;

	index = 1;
	c = 0;
	while (index < argc)
	{
		if (ft_strstr(argv[index], ".cor") != NULL)
		{
			arena->champion_count++;
			if (arena->champion_count > MAX_PLAYERS)
				vm_error(kErrTooManyChamps);
			arena->champ_index[c] = index;
			c++;
		}
		if (ft_strcmp(argv[index], "-n") == 0)
			index = number_champ(index, argc, argv, arena);
		if (ft_strcmp(argv[index], "-v") == 0)
			arena->visualizer.enabled = true;
		if (ft_strcmp(argv[index], "-dump") == 0)
			index = dump_flag(index, argc, argv, arena);
		index++;
	}
}

static void	add_file_name(t_arena *arena, char **argv)
{
	int	i;

	i = 0;
	while (i < arena->champion_count)
	{
		arena->champions[i].file_name = argv[arena->champions[i].argv_index];
		i++;
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
	if (arena->champion_count == 0 || arena->champion_count > MAX_PLAYERS)
		vm_error(kErrParams, NULL);
	while (arena->champion_count > index_fd)
	{
		if (arena->champions[index_fd].fd == 0)
		{
			arena->champions[index_fd].fd =
			open(argv[arena->champ_index[c]], O_RDONLY);
			arena->champions[index_fd].argv_index = arena->champ_index[c];
			arena->champions[index_fd].id = index_fd + 1;
			if (arena->champions[index_fd].fd < 0)
				vm_error(kErrFile, argv[arena->champions[index_fd].argv_index]);
			c++;
		}
		index_fd++;
	}
	add_file_name(arena, argv);
	//debug_check_args(arena);
}
