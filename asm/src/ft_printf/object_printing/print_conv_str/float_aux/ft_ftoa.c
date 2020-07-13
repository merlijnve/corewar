/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   float_rhs.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fmiceli <fmiceli@student.codam.nl...>        +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/01 19:29:43 by fmiceli       #+#    #+#                 */
/*   Updated: 2019/12/01 19:29:44 by fmiceli       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "float_aux.h"
#include "ft_printf_types.h"

static char	*float_special_value(t_ld_parts ld)
{
	if (ld.m == 0 && (ld.s_exp & LD_EXP) == 0)
		return (ft_strdup("*0"));
	if (ld.m & LD_FRACTION)
		return (ft_strdup("*nan"));
	return (ft_strdup("*inf"));
}

static int	get_dec_exp(int e)
{
	t_pf_f2u	magic_f;
	long double	ret;

	magic_f.ld.s_exp = 0x0000000000004000;
	magic_f.ld.m = 0xd49a784bcd1b8800;
	ret = e / magic_f.f;
	if (ret == 0)
		return (0);
	else if (e < 0)
		return (ret + 2);
	return (ret + 1);
}

static int	get_str_size(int d_exp, int prcs)
{
	int	size;

	size = (d_exp < 0 ? -d_exp + LD_PRCS : d_exp + LD_PRCS) + 3;
	if (d_exp < 0)
		size = (int)ft_min(prcs + 4 + LD_PRCS, size);
	size = (int)ft_max(prcs + 4 + (d_exp > 1 ? d_exp : 0) + LD_PRCS, size);
	return (size);
}

char		*ft_ftoa(t_pf_part *part)
{
	t_pf_f2u		f2u;
	int				d_exp;
	unsigned long	i;
	char			*str;
	size_t			size;

	f2u.f = part->value.s_ld_value;
	f2u.ld.s_exp &= 0x000000000000FFFF;
	if ((f2u.ld.s_exp & LD_EXP) == LD_EXP || f2u.ld.m == 0)
		return (float_special_value(f2u.ld));
	d_exp = get_dec_exp((f2u.ld.s_exp & LD_EXP) - LD_EXP_BIAS);
	size = get_str_size(d_exp, part->prcs);
	str = (char *)ft_memalloc(sizeof(char) * size);
	str = ft_memset(str, '0', size - 1);
	str[(d_exp < 0 ? 1 : d_exp + 1)] = '.';
	i = 0;
	str = set_left_of_dot(str, d_exp, f2u.ld, &i);
	str = set_right_of_dot(str, (int)size, f2u.ld, i);
	str = str_round(str, part->prcs);
	str[(ft_strchr(str, '.') - str) + part->prcs + (part->prcs ? 1 : 0)] = '\0';
	return (str);
}
