/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_print_num_full_d.c                             :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "pf_print_num_full.h"
#include "pf_print_nchar.h"

t_pf_ret	print_num_full_d(const char *str, int num_len, t_pf_obj *obj)
{
	size_t len;

	len = ft_strlen(str);
	if (num_len > (int)len)
		pf_print_nchar('0', num_len - len, obj);
	obj->print(str, LEN_NS, obj);
	return (PF_RET_SUCCESS);
}
