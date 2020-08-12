/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils_2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/09 20:48:30 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/08/12 14:40:39 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	IS_REGISTRY
**	Checks if given argument is a valid registry
*/

int		is_registry(int arg)
{
	if (arg > 0 && arg <= 16)
		return (OK);
	return (ERROR);
}
