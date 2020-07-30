/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_champions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/15 15:39:40 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/30 17:49:19 by merlijn       ########   odam.nl         */
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

int		check_null(unsigned char *bytecode)
{
	size_t	offset_1;
	size_t	offset_2;

	offset_1 = PROG_NAME_LENGTH + HEADER_SIZE;
	offset_2 = PROG_NAME_LENGTH + COMMENT_LENGTH + HEADER_SIZE + 2 * NULL_SIZE;
	if (bytecode[offset_1] == 0x00
	&& bytecode[offset_1 + 1] == 0x00
	&& bytecode[offset_1 + 2] == 0x00
	&& bytecode[offset_1 + 3] == 0x00
	&& bytecode[offset_2] == 0x00
	&& bytecode[offset_2 + 1] == 0x00
	&& bytecode[offset_2 + 2] == 0x00
	&& bytecode[offset_2 + 3] == 0x00)
		return (OK);
	return (ERROR);
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

int		check_file(int fd, t_champion *champion)
{
	ft_bzero(&champion->bytecode, CHAMP_FILESIZE + 1);
	read(fd, &champion->bytecode, CHAMP_FILESIZE);
	if (check_file_header(champion->bytecode) == ERROR)
		return (ERROR_BAD_HEADER);
	if (check_null(champion->bytecode) == ERROR)
		return (ERROR_BAD_NULL);
	champion->name = champion->bytecode + 4;
	champion->comment = champion->bytecode + 12 + PROG_NAME_LENGTH;
	champion->exec_code_size = get_exec_code_size(champion->bytecode);
	if (champion->exec_code_size > CHAMP_MAX_SIZE)
		return (ERROR_BAD_SIZE);
	champion->exec_code = champion->bytecode + CHAMP_FILESIZE - CHAMP_MAX_SIZE;
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
		ft_printf("filename:\n%s\n", champions[i].file_name);
		ft_printf("name:\n%s\n", champions[i].name);
		ft_printf("comment:\n%s\n", champions[i].comment);
		ft_printf("exec_code_size:\n%d\n", champions[i].exec_code_size);
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
				ft_printf("Error: File %s has an invalid header\n",
				champions[i].file_name);
			if (ret == ERROR_BAD_SIZE)
				ft_printf("Error: File %s has too large a code (%d bytes >"
				" 682 bytes\n", champions[i].file_name,
				champions[i].exec_code_size);
			if (ret == ERROR_BAD_NULL)
				ft_printf("Error: File %s is not properly formatted "
				"with nulls\n", champions[i].file_name);
			exit(ret);
		}
		i++;
	}
	return (OK);
}
