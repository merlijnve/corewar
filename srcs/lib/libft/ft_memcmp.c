/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:15 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	t_index			idx;
	unsigned char	*ls1;
	unsigned char	*ls2;

	if (n == 0)
		return (0);
	ls1 = ((unsigned char*)s1);
	ls2 = ((unsigned char*)s2);
	idx = 0;
	while (idx < n && ls1[idx] == ls2[idx])
		idx++;
	if (idx == n)
		return ((int)(ls1[idx - 1] - ls2[idx - 1]));
	else
		return ((int)(ls1[idx] - ls2[idx]));
}
