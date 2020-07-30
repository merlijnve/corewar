/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:25:41 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/07/29 16:33:36 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <libft.h>
#include <unistd.h>

int		ft_error(int e)
{
	if (e == ERR_PARAMS)
		print_usage();
	else if (e == ERR_FILE)
		ft_dprintf(STDERR_FILENO, "Error reading file, might be empty.\n");
	return (-1);
}
