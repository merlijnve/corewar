/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_champions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/15 15:39:40 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/17 15:52:43 by mvan-eng      ########   odam.nl         */
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

int		check_file(int fd, t_champion *champion)
{
	ft_bzero(&champion->bytecode, CHAMP_FILESIZE + 1);
	read(fd, &champion->bytecode, CHAMP_FILESIZE);
	if (check_file_header(&(*champion->bytecode)) != OK)
		return (ERROR_BAD_HEADER);
	champion->name = champion->bytecode + 4;
	champion->comment = champion->bytecode + 12 + PROG_NAME_LENGTH;
	ft_printf("champion name: %s\n", champion->name);
	ft_printf("champion comment: %s\n", champion->comment);
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
			ft_printf("Error: File %s has an invalid header\n", "kechass");
		exit(ERROR_BAD_HEADER);
	}
	return (OK);
}

int		main(void)
{
	int	fd;

	fd = open("good_kitty.cor", O_RDONLY);
	check_champions(&fd);
	return (OK);
}
