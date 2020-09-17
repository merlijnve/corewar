/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   shared_utils.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:41:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/08 14:41:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <op.h>
#include "shared_utils.h"
#include "error.h"

int		is_readable(int chr)
{
	if (ft_strchr("0123456789abcdefghijklmnopqrstuvwxyz"
					"ABCDEFGHIJKLMNOPQRSTUVWXYZ-_", chr))
		return (1);
	return (0);
}

int		is_label_chr(int chr)
{
	if (ft_strchr(LABEL_CHARS, chr))
		return (1);
	return (0);
}

int		is_comment_chr(int chr)
{
	if (ft_strchr(COMMENT_CHARS, chr))
		return (1);
	return (0);
}

t_ret	asm_regtoint(char *str)
{
	int number;

	if (*str != 'r')
		return (kError);
	number = ft_atoi(&str[1]);
	return (number >= 0 ? number : kError);
}
