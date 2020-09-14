/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_chr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 17:25:00 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/14 17:25:00 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*ft_find_chr(const char *line, char chr, int (skip)(int chr))
{
	t_index idx;

	idx = 0;
	if (skip != NULL)
		while (line[idx] != '\0' && skip(line[idx]) && line[idx] != chr)
			idx++;
	else
		while (line[idx] != '\0' && line[idx] != chr)
			idx++;

	if (line[idx] == chr)
		return (&line[idx]);
	return (NULL);
}
