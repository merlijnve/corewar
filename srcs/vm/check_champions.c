/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_champions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/15 15:39:40 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/12 12:41:21 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <unistd.h>

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
			return (kError);
	}
	return ((int)idx);
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
		return (kErrBadHeader);
	if (champion->champ.nt_comment != 0 || champion->champ.nt_name != 0)
		return (kErrBadNull);
	if (champion->champ.size > CHAMP_MAX_SIZE)
		return (kErrBadSize);
	return (kOk);
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
		if (champions[i].id > 0) {
			ret = check_file(champions[i].fd, &champions[i]);
			if (ret < 0)
			{
				vm_error(ret, champions[i].file_name);
				exit(ret);
			}
		}
		i++;
	}
	return (kOk);
}
