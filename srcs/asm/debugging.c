/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debugging.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 15:29:33 by floris        #+#    #+#                 */
/*   Updated: 2020/06/11 15:29:35 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <unistd.h>

#include "debugging.h"

#pragma mark - printing utils

void		print_file(char *file)
{
	ft_printf("FILE:\n ++++ START ++++\n%s\n ++++ END ++++\n\n", file);
}

void		print_lines(t_list *lines)
{
	ft_printf("LINES:\n ++++ START ++++\n");
	while (lines != NULL)
	{
		ft_printf("line: %.4d | %s\n", lines->content_size, lines->content);
		lines = lines->next;
	}
	ft_printf("++++ END ++++\n\n");
}

void		print_tokens(t_list *tokens)
{
	t_tksave *part;

	ft_printf("LINES:\n ++++ START ++++\n");
	while (lines != NULL)
	{
		part = lines->content;
		ft_printf("token: %.3d:%.3d %d | %s\n",
					part->loc.ln, part->loc.chr, part->token, part->str);
		lines = lines->next;
	}
	ft_printf("++++ END ++++\n\n");
}

void		print_bc(t_asm *asmblr, size_t size)
{
	debug_print_mem(asmblr->bytecode.bytecode, size);
	ft_printf("\n");
}

#pragma mark - memory_print

static void	ft_print_chars(const void *addr, size_t size)
{
	int		idx;
	char	c;

	idx = 0;
	while (idx < (int)size)
	{
		c = *(char const *)(addr + idx);
		if (c < ' ' || c > '~')
			write(1, ".", 1);
		else
			write(1, &c, 1);
		idx++;
	}
	write(1, "\n", 1);
}

static void	ft_print_two_bytes(const void *addr, size_t size)
{
	int				cnt;
	char			c;

	cnt = 0;
	while (cnt < 2)
	{
		if (2 - cnt >= (int)size)
			write(1, "--", 2);
		else
		{
			if ((c = *(unsigned char const *)(addr + cnt) / 16) <= 9)
				c += '0';
			else
				c += 'a' - 10;
			write(1, &c, 1);
			if ((c = *(unsigned char const *)(addr + cnt) % 16) <= 9)
				c += '0';
			else
				c += 'a' - 10;
			write(1, &c, 1);
		}
		cnt++;
	}
	write(1, " ", 1);
}

static void	ft_print_block(const void *addr, size_t size)
{
	unsigned int	cnt;
	size_t			tmp_size;

	tmp_size = size;
	cnt = 0;
	while (cnt < 16)
	{
		if (cnt >= size)
			write(1, "      ", 5);
		else
		{
			ft_print_two_bytes(addr + cnt, size);
		}
		tmp_size -= 2;
		cnt += 2;
	}
	write(1, " ", 1);
}

static void	ft_print_row(const void *addr, size_t size)
{
	ft_print_block(addr, size);
	ft_print_chars(addr, size);
}

void		debug_print_mem(const void *addr, size_t size)
{
	long	temp_size;

	temp_size = (long)size;
	while (temp_size > 0)
	{
		if (temp_size <= 16)
			ft_print_row(addr + (size - temp_size), temp_size);
		else
			ft_print_row(addr + (size - temp_size), 16);
		temp_size -= 4 * 4;
	}
}
