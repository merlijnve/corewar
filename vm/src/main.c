/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/09 14:37:52 by joris         #+#    #+#                 */
/*   Updated: 2020/07/21 16:43:21 by jboer         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			main(int argc, char **argv)
{
	t_vm		vm_s;
	t_champion	champions[MAX_PLAYERS];

	ft_bzero(&champions, sizeof(champions));
	ft_bzero(&vm_s, sizeof(vm_s));
	check_args(argc, argv, &vm_s, &(*champions));
	return (OK);
}
