/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   add_flags.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/09/02 12:49:06 by jboer         #+#    #+#                 */
/*   Updated: 2020/05/22 14:15:52 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static char	*space_plus(char *str, int i)
{
	while (str[i] && str[i] < '0' && str[i] > '9' && str[i] != '.')
		i++;
	if (i == 0 && str[i] != '-')
	{
		str = ft_straddtofront(str, " ");
		if (!str)
			return (NULL);
	}
	return (str);
}

char		*add_flags(char *str, t_print *print)
{
	int		i;

	i = 0;
	if (print->flags[2] == 1)
	{
		while (str[i] && str[i] < '0' && str[i] > '9' && str[i] != '.')
			i++;
		if (i == 0 && str[i] != '-')
		{
			str = ft_straddtofront(str, "+");
			if (!str)
				return (NULL);
		}
	}
	if (print->flags[4] && !print->flags[2])
	{
		str = space_plus(str, i);
		if (!str)
			return (NULL);
	}
	return (str);
}
