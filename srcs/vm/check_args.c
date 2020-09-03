/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 18:53:34 by joris         #+#    #+#                 */
/*   Updated: 2020/09/03 17:21:00 by jboer         ########   odam.nl         */
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
		vm_error(ERR_PARAMS);
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

	if (index > argc - 1)
		vm_error(ERR_PARAMS);
	player_n = ft_atoi(argv[index]);
	if (player_n > MAX_PLAYERS || player_n <= 0 ||
	arena->n_flag || arena->champions[player_n - 1].fd != 0)
	{
		debug_printf("TESTING... %d\n", player_n);
		vm_error(ERR_PARAMS);
	}
	index++;
	if (ft_strstr(argv[index], ".cor") != NULL)
	{
		arena->champions[player_n - 1].fd = open(argv[index], O_RDONLY);
		arena->champions[player_n - 1].argv_index = index;
		if (arena->champions[player_n - 1].fd < 0)
			vm_error(ERR_FILE, argv[index]);
		arena->champion_count++;
		if (arena->champion_count > MAX_PLAYERS)
			vm_error(ERR_TOO_MANY_CHAMP, NULL);
	}
	else
		vm_error(ERR_PARAMS);
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
				vm_error(ERR_TOO_MANY_CHAMP);
			arena->champions[arena->champion_count - 1].argv_index = index;
		}
		if (ft_strcmp(argv[index], "-n") == 0)
		{
			ft_printf("%s, strcmp: %d\n", argv[index],
			ft_strcmp(argv[index], "-n"));
			index++;
			index = number_champ(index, argc, argv, arena);
		}
		if (ft_strcmp(argv[index], "-dump") == 0)
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
	loop_args(argc, argv, arena);
	if (arena->champion_count == 0 || arena->n_flag > arena->champion_count)
		vm_error(ERR_PARAMS, NULL);
	while (arena->champion_count > index_fd)
	{
		if (arena->champions[index_fd].fd == 0)
		{
			arena->champions[index_fd].fd =
			open(argv[arena->champions[index_fd].argv_index], O_RDONLY);
			if (arena->champions[index_fd].fd < 0)
				vm_error(ERR_FILE, argv[arena->champions[index_fd].argv_index]);
		}
		index_fd++;
	}
	while (c < arena->champion_count)
	{
		arena->champions[c].file_name = argv[arena->champions[c].argv_index];
		c++;
	}
}
