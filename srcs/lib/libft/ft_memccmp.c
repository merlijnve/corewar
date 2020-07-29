/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memccmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:15 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memccmp(const void *s1, const void *s2, int c, size_t n)
{
	t_index			idx;
	unsigned char	*ls1;
	unsigned char	*ls2;

	ls1 = ((unsigned char*)s1);
	ls2 = ((unsigned char*)s2);
	idx = 0;
	while (ls1[idx] == ls2[idx])
	{
		if (idx == n - 1)
		{
			idx++;
			break ;
		}
		if (ls1[idx] == (unsigned char)c ||
			ls2[idx] == (unsigned char)c)
		{
			idx++;
			break ;
		}
		idx++;
	}
	return (ls1[idx] - ls2[idx]);
}
