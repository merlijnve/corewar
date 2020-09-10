/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dump.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 16:17:34 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/10 16:58:42 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	dump(uint8_t *mem)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < MEM_SIZE)
	{
		ft_printf("%3d] ", i / 64);
		while (j < 64)
		{
			ft_printf("%02X ", mem[i + j]);
			j++;
		}
		ft_printf("[%3d\n", i / 64);
		j = 0;
		i += 64;
	}
}
