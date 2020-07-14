/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:37:52 by joris         #+#    #+#                 */
/*   Updated: 2020/07/13 17:24:38 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/vm.h"

int			main(int argc, char **argv)
{
	t_vm	vm_s;
	int		n_champs;

	ft_bzero(&vm_s, sizeof(vm_s));
	if (check_arguments(argc, argv, &vm_s) = ERROR)
		return (ERROR);	
}
