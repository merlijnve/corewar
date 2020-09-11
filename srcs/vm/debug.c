/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 20:58:11 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/11 16:10:13 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include "vm.h"

void        debug_print_hex(unsigned char *str, int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        ft_printf("%02X", str[i]);
        i++;
    }
    ft_printf("\n");
}

void	debug_print_mem(const void *addr, size_t size)
{
	size_t			i;
	size_t 			j;
	unsigned char	*p;
	char 			*str;
    size_t             width;
    
    width = 64;
	str = "0123456789abcdef";
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < width && i + j < size)
		{
            debug_printf("%02hhX", p[i + j]);
			if (j % 2)
				debug_printf(" ");
			j += 1;
		}
		while (j < width)
		{
			debug_printf(" ");
			if (j % 2)
				debug_printf(" ");
			j++;
		}
		j = 0;
		while (j < width && i + j < size)
		{
            debug_printf("%c", ft_isprint(p[i + j]) ? p[i + j] : '.');
			j += 1;
		}
		debug_printf("\n");
		i += width;
	}
}

void		debug_check_args(t_arena *arena)
{
	int		i = 0;

	ft_printf("champ 1:\nchamp->id: %i\nchamp->fd: %i\nchamp->argv_index: %i\nchamp->file_name: %s\n", arena->champions[i].id, arena->champions[i].fd, arena->champions[i].argv_index, arena->champions[i].file_name);
	i++;
	ft_printf("champ 2:\nchamp->id: %i\nchamp->fd: %i\nchamp->argv_index: %i\nchamp->file_name: %s\n", arena->champions[i].id, arena->champions[i].fd, arena->champions[i].argv_index, arena->champions[i].file_name);
	i++;
	ft_printf("champ 1:\nchamp->id: %i\nchamp->fd: %i\nchamp->argv_index: %i\nchamp->file_name: %s\n", arena->champions[i].id, arena->champions[i].fd, arena->champions[i].argv_index, arena->champions[i].file_name);
	i++;
	ft_printf("champ 1:\nchamp->id: %i\nchamp->fd: %i\nchamp->argv_index: %i\nchamp->file_name: %s\n", arena->champions[i].id, arena->champions[i].fd, arena->champions[i].argv_index, arena->champions[i].file_name);
}

void		debug_print_cursor(t_cursor *cursor)
{
	debug_printf("-- Cursor id: %d --\n", cursor->id);
	debug_printf(" - current pos: %d\n\n", cursor->pos);
}

void		debug_print_cursors(t_cursor *cursors)
{
	t_cursor *start;

	start = cursors;

	while (start != NULL)
	{
		debug_print_cursor(start);
		start = start->next;
	}
}

void        debug_print_map(t_arena *arena)
{
    debug_print_mem(arena->mem, MEM_SIZE);
}

int		debug_printf(const char *format, ...)
{
	va_list		ap;
    int ret;
    int fd;

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
	//t_cw_champ_file champ;

    debug_printf("[DEBUG] Champion: %s\n", champion->champ.name);
    debug_printf("filename: '%s'\n", champion->file_name);
    debug_printf("name: '%s'\n", champion->champ.name);
	debug_printf("magic: %#x vs %#x\n", champion->champ.magic, COREWAR_EXEC_MAGIC, MAGIC_NUMBER_LEN);
	debug_printf("exec size: '%d' \n", champion->champ.size);
	debug_printf("comment: '%s'\n", champion->champ.comment);
	debug_printf("---\n\n");
}
