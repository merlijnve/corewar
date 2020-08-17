/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 20:58:11 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/08/09 20:08:43 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "ft_printf_types.h"
#include "ft_print_functions.h"

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

void	print_memory(const void *addr, size_t size)
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

void        debug_print_map(t_arena *arena)
{
    print_memory(arena->mem, MEM_SIZE);
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