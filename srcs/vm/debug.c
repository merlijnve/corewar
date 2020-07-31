/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/29 20:58:11 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/07/31 18:29:41 by wmisiedj      ########   odam.nl         */
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
            printf_debug("%02hhX", p[i + j]);
			if (j % 2)
				printf_debug(" ");
			j += 1;
		}
		while (j < width)
		{
			printf_debug(" ");
			if (j % 2)
				printf_debug(" ");
			j++;
		}
		j = 0;
		while (j < width && i + j < size)
		{
            printf_debug("%c", ft_isprint(p[i + j]) ? p[i + j] : '.');
			j += 1;
		}
		printf_debug("\n");
		i += width;
	}
}

void        debug_print_map(t_arena *arena)
{
    print_memory(arena->mem, MEM_SIZE);
}

int		printf_debug(const char *format, ...)
{
	va_list		ap;
    int ret;
    int fd;

    ret = 0;
    fd = open(DEBUG_FILE, O_WRONLY | O_APPEND | O_CREAT, 0666);
	va_start(ap, format);
    ft_vdprintf(STDOUT_FILENO, format, ap);
    ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}

void	debug_print_champion(t_champion *champion)
{
	t_cw_champ_file champ;

    printf_debug("[DEBUG] Champion: %s\n", champion->champ.name);
    printf_debug("filename: '%s'\n", champion->file_name);
    printf_debug("name: '%s'\n", champion->champ.name);
	printf_debug("magic: %#x vs %#x\n", champion->champ.magic, COREWAR_EXEC_MAGIC, MAGIC_NUMBER_LEN);
	printf_debug("exec size: '%d' \n", champion->champ.size);
	printf_debug("comment: '%s'\n", champion->champ.comment);
	printf_debug("---\n\n");
}