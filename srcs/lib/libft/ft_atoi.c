/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:14 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:35:17 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		get_options(const char *str, int *is_negative, t_index *index)
{
	while (ft_isspace(str[*index]))
		*index += 1;
	if (str[*index] == '-')
	{
		*index += 1;
		*is_negative = 1;
	}
	else if (str[*index] == '+')
		*index += 1;
}

int				ft_atoi(const char *str)
{
	t_index				index;
	int					is_negative;
	unsigned long long	result;

	index = 0;
	is_negative = 0;
	result = 0;
	get_options(str, &is_negative, &index);
	while (ft_isdigit(str[index]))
	{
		result *= 10;
		result += str[index] - '0';
		index++;
		if (result >= 9223372036854775808UL)
		{
			if (is_negative)
				return (0);
			return (-1);
		}
	}
	if (is_negative)
		return ((int)(-result));
	return ((int)(result));
}
