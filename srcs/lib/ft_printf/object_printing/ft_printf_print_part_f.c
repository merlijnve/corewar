/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_print_part_f.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/30 16:46:01 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:33:51 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>
#include "pf_print_conv.h"
#include "float_aux.h"

static int	is_negative(t_pf_part *part)
{
	t_pf_f2u	f2u;

	f2u.f = part->value.s_ld_value;
	f2u.ld.s_exp &= 0x000000000000FFFF;
	return (f2u.ld.s_exp & LD_SIGN);
}

static char	*special_case_zero(char *str, t_pf_part *part)
{
	free(str);
	str = malloc(part->prcs + 3);
	ft_memcpy(str, "0.", 2);
	ft_memset(str + 2, '0', part->prcs);
	str[part->prcs + 2] = '\0';
	return (str);
}

static char	*special_case_nan(char *str, t_pf_part *part)
{
	free(str);
	str = malloc(5);
	if (part->conv == XF_CONV)
		ft_memcpy(str, "*NAN", 5);
	else
		ft_memcpy(str, "*nan", 5);
	part->prcs = 3;
	return (str);
}

static char	*special_case_inf(char *str, t_pf_part *part)
{
	free(str);
	str = malloc(6);
	if (is_negative(part))
	{
		ft_memcpy(str, "*-inf", 6);
		part->prcs = 4;
	}
	else if (part->flags & PF_PL_FLAG || (part->flags & PF_SP_FLAG))
	{
		if (part->conv == XF_CONV)
			ft_memcpy(str, part->flags & PF_PL_FLAG ? "*+INF" : "* INF", 5);
		else
			ft_memcpy(str, part->flags & PF_PL_FLAG ? "*+inf" : "* inf", 5);
		part->prcs = 4;
	}
	else
	{
		ft_memcpy(str, (part->conv == XF_CONV) ? "*INF" : "*inf", 5);
		part->prcs = 3;
	}
	return (str);
}

t_pf_ret	ft_printf_print_part_f(t_pf_obj *obj, t_pf_part *part)
{
	char	*str;
	size_t	idx;

	idx = 0;
	obj->part->prcs = (obj->part->prcs == PRCS_NS ? 6 : obj->part->prcs);
	str = ft_ftoa(part);
	if (str == NULL)
		return (PF_RET_ERROR);
	if (part->flags & PF_MN_FLAG && part->flags & PF_ZR_FLAG)
		part->flags &= ~(PF_ZR_FLAG);
	while (str[idx] != '\0' && (str[idx] == '0' && str[idx + 1] != '.') &&
	!(str[idx] == '0' && str[idx + 1] == '\0'))
		idx++;
	if (str[idx] == '*' && str[idx + 1] == '0')
		str = special_case_zero(str, part);
	if (str[idx] == '*' && str[idx + 1] == 'n')
		str = special_case_nan(str, part);
	if (str[idx] == '*' && str[idx + 1] == 'i')
		str = special_case_inf(str, part);
	pf_print_pad_conv_f(&str[idx], part, obj);
	free(str);
	return (PF_RET_SUCCESS);
}
