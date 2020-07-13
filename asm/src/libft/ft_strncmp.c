/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strncmp.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:19 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:27 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	t_index			idx;
	unsigned char	*ls1;
	unsigned char	*ls2;

	ls1 = ((unsigned char*)s1);
	ls2 = ((unsigned char*)s2);
	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n && ls1[idx] == ls2[idx])
	{
		if (ls1[idx] == '\0' || ls2[idx] == '\0')
			return ((int)(ls1[idx] - ls2[idx]));
		idx++;
	}
	if (idx == n)
		return ((int)(ls1[idx - 1] - ls2[idx - 1]));
	return ((int)(ls1[idx] - ls2[idx]));
}
