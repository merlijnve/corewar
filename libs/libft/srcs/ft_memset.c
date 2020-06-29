/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: jboer <jboer@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/21 11:34:36 by jboer         #+#    #+#                 */
/*   Updated: 2020/04/14 15:58:11 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	n;
	char			*strb;

	strb = b;
	n = (unsigned char)c;
	while (len > 0)
	{
		*strb = n;
		strb++;
		len--;
	}
	return (b);
}
