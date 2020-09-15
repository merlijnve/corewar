/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 20:58:11 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/15 13:42:56 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "vm.h"

void	debug_check_args(t_arena *arena)
{
	int	i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		ft_printf("champ %d:\nchamp->id: %i\nchamp->fd: %i\nchamp->argv_index: "
		"%i\nchamp->file_name: %s\nchamp->champ.name: %s \n\n", i,
		arena->champions[i].id, arena->champions[i].fd,
		arena->champions[i].argv_index, arena->champions[i].file_name,
		arena->champions[i].champ.name);
		i++;
	}
	ft_printf("Champion Count %d\n", arena->champion_count);
}

void	debug_print_cursor(t_cursor *cursor)
{
	debug_printf("-- Cursor id: %d --\n", cursor->id);
	debug_printf(" - current pos: %d\n\n", cursor->pos);
}

void	debug_print_cursors(t_cursor *cursors)
{
	t_cursor *start;

	start = cursors;
	while (start != NULL)
	{
		debug_print_cursor(start);
		start = start->next;
	}
}

int		debug_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;
	int		fd;

	ret = 0;
	fd = STDOUT_FILENO;
	if (!DEBUG_ENABLED)
		return (0);
	if (DEBUG_FILE)
		fd = open(DEBUG_FILE, O_WRONLY | O_APPEND | O_CREAT, 0666);
	va_start(ap, format);
	if (DEBUG_PRINT)
		ft_vdprintf(STDOUT_FILENO, format, ap);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

void	debug_print_champion(t_champion *champion)
{
	debug_printf("[DEBUG] Champion: %s\n", champion->champ.name);
	debug_printf("filename: '%s'\n", champion->file_name);
	debug_printf("name: '%s'\n", champion->champ.name);
	debug_printf("magic: %#x vs %#x\n", champion->champ.magic,
	COREWAR_EXEC_MAGIC, MAGIC_NUMBER_LEN);
	debug_printf("exec size: '%d' \n", champion->champ.size);
	debug_printf("comment: '%s'\n", champion->champ.comment);
	debug_printf("---\n\n");
}
