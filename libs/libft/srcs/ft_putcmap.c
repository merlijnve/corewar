/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putcmap.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/28 17:51:51 by jboer         #+#    #+#                 */
/*   Updated: 2020/04/14 15:58:24 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putcmap(char **ar)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (ar[i])
	{
		ft_putstr(ar[i]);
		ft_putchar('\n');
		i++;
	}
}
