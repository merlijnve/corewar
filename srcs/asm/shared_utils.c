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

int is_label_chr(int chr)
{
	if (ft_strchr(LABEL_CHARS, chr))
		return (1);
	return (0);
}

int	is_comment_chr(int chr)
{
	if (ft_strchr(COMMENT_CHARS, chr))
		return (1);
	return (0);
}