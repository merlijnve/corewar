/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_mod.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:14 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:25 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_mod(long a, long b)
{
	long result;

	result = a % b;
	return (result >= 0 ? result : result + b);
}
