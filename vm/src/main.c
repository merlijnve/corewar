/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:37:52 by joris         #+#    #+#                 */
/*   Updated: 2020/07/14 19:50:52 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int argc, char **argv)
{
	t_vm	vm_s;

	ft_bzero(&vm_s, sizeof(vm_s));
	if (check_args(argc, argv, &vm_s) == ERROR)
		return (ERROR);
	return (OK);
}
