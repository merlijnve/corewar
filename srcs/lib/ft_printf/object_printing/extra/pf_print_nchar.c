/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pf_print_nchar.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:32:21 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_print_nchar.h"

t_pf_ret	pf_print_nchar(int c, size_t n, t_pf_obj *obj)
{
	char str[16];

	ft_memset(str, c, 16);
	while (n >= 16)
	{
		obj->print(str, 16, obj);
		n -= 16;
	}
	if (n != 0)
		obj->print(str, n, obj);
	return (PF_RET_SUCCESS);
}
