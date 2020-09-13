/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 13:00:00 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/13 13:00:00 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_chrcnt(char *str, int chr, size_t len)
{
	t_index		idx;
	int			cnt;

	idx = 0;
	cnt = 0;
	while (str[idx] != '\0' && (len >= idx || len == 0))
	{
		if (str[idx] == chr)
			cnt++;
	}
	return (cnt);
}
