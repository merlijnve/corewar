/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_champions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/15 15:39:40 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/20 16:21:20 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <unistd.h>

int		check_file_header(char *buff)
{
	if ((unsigned char)buff[0] == 0x00 && (unsigned char)buff[1] == 0xEA &&
	(unsigned char)buff[2] == 0x83 && (unsigned char)buff[3] == 0xF3)
		return (OK);
	return (ERROR);
}

/*
**	GET_EXEC_CODE_SIZE
**	calculates and returns exec_code_size in given bytecode
*/

size_t	get_exec_code_size(char *bytecode)
{
	size_t size;

	size = ((unsigned char)bytecode[PROG_NAME_LENGTH + 8] << 24) |
	((unsigned char)bytecode[PROG_NAME_LENGTH + 9] << 16) |
	((unsigned char)bytecode[PROG_NAME_LENGTH + 10] << 8) |
	((unsigned char)bytecode[PROG_NAME_LENGTH + 11]);
	return (size);
}

int		check_null(char *bytecode)
{
	if (bytecode[PROG_NAME_LENGTH + 4] == 0x00
	&& bytecode[PROG_NAME_LENGTH + 5] == 0x00
	&& bytecode[PROG_NAME_LENGTH + 6] == 0x00
	&& bytecode[PROG_NAME_LENGTH + 7] == 0x00
	&& bytecode[PROG_NAME_LENGTH + COMMENT_LENGTH + 12] == 0x00
	&& bytecode[PROG_NAME_LENGTH + COMMENT_LENGTH + 13] == 0x00
	&& bytecode[PROG_NAME_LENGTH + COMMENT_LENGTH + 14] == 0x00
	&& bytecode[PROG_NAME_LENGTH + COMMENT_LENGTH + 15] == 0x00)
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
	if (check_file_header(&(*champion->bytecode)) == ERROR)
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

int		check_champions(int *fds)
{
	t_champion	champions[MAX_PLAYERS];
	int			i;
	int			ret;

	i = 0;
	ft_bzero(&champions, sizeof(champions));
	ret = check_file(fds[i], &champions[i]);
	if (ret < OK)
	{
		if (ret == ERROR_BAD_HEADER)
			ft_printf("Error: File %s has an invalid header\n", "[filename]");
		if (ret == ERROR_BAD_SIZE)
			ft_printf("Error: File %s has too large a code (%d bytes >"
			" 682 bytes\n", "[filename]", champions[i].exec_code_size);
		if (ret == ERROR_BAD_NULL)
			ft_printf("Error: File %s is not properly formatted with nulls\n",
			"[filename]");
		exit(ret);
	}
	return (OK);
}

int		main(int argc, char **argv)
{
	int	fd;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	check_champions(&fd);
	return (OK);
}
