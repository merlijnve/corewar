/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:16 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:26 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!(dst == src))
	{
		if (src < dst)
			ft_memrcpy(dst, src, len);
		else
			ft_memcpy(dst, src, len);
	}
	return (dst);
}
