/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strisdigit.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/12 11:15:34 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/06/12 11:15:35 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strisdigit(const char *s)
{
	t_index idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (!ft_isdigit(s[idx]))
			return (0);
		idx++;
	}
	return (1);
}
