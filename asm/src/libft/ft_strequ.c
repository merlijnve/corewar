/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strequ.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:18 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:26 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int		result;

	result = ft_strcmp(s1, s2);
	if (result == 0)
		return (1);
	return (0);
}
