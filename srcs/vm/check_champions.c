/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_champions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/15 15:39:40 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/31 17:37:25 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <unistd.h>

/*
**	CHECK_FILE_HEADER
**	compares first 4 bytes for correct magic header 0x00EA83F3
*/

int		check_file_header(unsigned char *bytecode)
{
	if (bytecode[0] == 0x00 && bytecode[1] == 0xEA &&
	bytecode[2] == 0x83 && bytecode[3] == 0xF3)
		return (OK);
	return (ERROR);
}

/*
**	GET_EXEC_CODE_SIZE
**	calculates and returns exec_code_size in given bytecode
*/

size_t	get_exec_code_size(unsigned char *bytecode)
{
	size_t	size;
	size_t	offset;

	offset = PROG_NAME_LENGTH + NULL_SIZE + HEADER_SIZE;
	size = (bytecode[offset] << 24) |
	(bytecode[offset + 1] << 16) |
	(bytecode[offset + 2] << 8) |
	(bytecode[offset + 3]);
	return (size);
}

/*
**	CHECK_NULL
**	checks if both nulls in .cor file are proper nulls
**	offset is used to indicate where a null is supposed to start
*/

int		check_null(t_champion *champion)
{
	return (OK);
}

/*
**	CHECK_FILE
**	reads bytecode from champion_fd
**	validates and sets:
**	- magic header
**	- name
**	- comment
**	- exec_code_size
**	- exec_code
*/

int		read_champion_file(int fd, t_cw_champ_file *cw_file)
{
	t_index idx;
	ssize_t	rbytes;

	idx = 0;
	rbytes = 10;
	while (rbytes != EOF && rbytes > 0)
	{
		rbytes = read(fd, &cw_file[idx], CHAMP_FILESIZE - idx);
		idx += rbytes;
		if (idx >= CHAMP_FILESIZE && rbytes != EOF)
			return (ERROR);
	}
	return (idx);
}

int		check_file(int fd, t_champion *champion)
{
	int ret;
	
	ret = read_champion_file(fd, &champion->champ);
	if (champion->champ.magic == COREWAR_EXEC_MAGICR)
	{
		champion->champ.magic = rev_bytes_32(champion->champ.magic);
		champion->champ.size = rev_bytes_32(champion->champ.size);
	}

	
	debug_print_champion(champion);
	if (champion->champ.magic != COREWAR_EXEC_MAGIC)
		return (ERROR_BAD_HEADER);
	if (champion->champ.nt_comment != 0 || champion->champ.nt_name != 0)
		return (ERROR_BAD_NULL);
	if (champion->champ.size > CHAMP_MAX_SIZE)
		return (ERROR_BAD_SIZE);
	return (OK);
}

/*
**	PRINT_CHAMPIONS
**	debug function for printing champion data
*/


void	print_champions(t_champion *champions, int champion_count)
{
	int	i;

	i = 0;
	while (i < champion_count)
	{
		debug_print_champion(&champions[i]);
		i++;
	}
}

/*
**	CHECK_CHAMPIONS
**	loops through array of champions to get checked
*/

int		check_champions(t_champion *champions, int champion_count)
{
	int			i;
	int			ret;

	i = 0;
	while (i < champion_count)
	{
		ret = check_file(champions[i].fd, &champions[i]);
		if (ret < OK)
		{
			if (ret == ERROR_BAD_HEADER)
				ft_printf("Error: File %s has an invalid header.\n",
				champions[i].file_name);
			if (ret == ERROR_BAD_SIZE)
				ft_printf("Error: File %s has too large a code.\n", champions[i].file_name);
			if (ret == ERROR_BAD_NULL)
				ft_printf("Error: File %s is not properly formatted "
				"with nulls\n", champions[i].file_name);
			exit(ret);
		}
		i++;
	}
	return (OK);
}
