/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   dump.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: merlijn <merlijn@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 16:17:34 by merlijn       #+#    #+#                 */
/*   Updated: 2020/09/11 14:53:03 by merlijn       ########   odam.nl         */
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
		ft_printf("0x%04x : ", i);
		while (j < 64)
		{
			ft_printf("%02x ", mem[i + j]);
			j++;
		}
		ft_printf("\n");
		j = 0;
		i += 64;
	}
}
