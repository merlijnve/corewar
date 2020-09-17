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

#include "asm.h"

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
