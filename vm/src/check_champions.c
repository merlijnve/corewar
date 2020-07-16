/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_champions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/15 15:39:40 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/16 11:33:49 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <unistd.h>

int		check_file(int fd, t_champion *champion)
{
	char	buff[16 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE + 1];
	size_t	file_size;
	int		out;

	out = open("output.txt", O_RDWR);
	ft_printf("fd of output.txt: %d\nfd of input: %d\n", out, fd);
	(void)champion;
	file_size = 16 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE;
	ft_bzero(&buff, file_size + 1);
	read(fd, &buff, file_size);
	ft_putendl(buff);
	return (0);
}

int		check_champions(int *fds)
{
	t_champion	champions[MAX_PLAYERS];
	int			i;

	i = 0;
	ft_bzero(&champions, sizeof(champions));
	check_file(fds[i], &champions[i]);
	return (0);
}

int		main(void)
{
	int	fd;

	fd = open("Explosive_Kitty.cor", O_RDONLY);
	check_champions(&fd);
	return (0);
}