/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_isspace.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 19:30:31 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isspace_h(int c)
{
	if (c == '\t' || c == ' ')
		return (1);
	else
		return (0);
}

int		ft_isspace_v(int c)
{
	if (c == '\n' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int		ft_isspace(int c)
{
	if (ft_isspace_h(c) || ft_isspace_v(c))
		return (1);
	else
		return (0);
}
