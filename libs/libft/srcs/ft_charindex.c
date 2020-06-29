/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_charindex.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/04 15:12:33 by jboer         #+#    #+#                 */
/*   Updated: 2020/04/14 15:56:03 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_charindex(const char *str, char c)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
