/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putmembe.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:14 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putmembe(void *mem, uint64_t num, size_t size)
{
	uint8_t	*mems;
	t_index idx;

	idx = 0;
	mems = mem;

	while (idx + 1 <= size)
	{
		mems[idx] =
		((num & (0xFFL << (size - (idx + 1)) * 8)) >> (size - (idx + 1)) * 8);
		idx++;
	}
}
