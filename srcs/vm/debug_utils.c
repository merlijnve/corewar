/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debug_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/15 13:42:03 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/09/15 13:42:14 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	debug_print_hex(unsigned char *str, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		ft_printf("%02X", str[i]);
		i++;
	}
	ft_printf("\n");
}
