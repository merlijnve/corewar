/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_find_chr.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 17:25:00 by ffredrik      #+#    #+#                 */
/*   Updated: 2020/09/17 13:37:10 by floris        ########   odam.nl         */
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

const char	*ft_find_set
	(const char *line, int (in_set)(int chr), int (skip)(int chr))
{
	t_index idx;

	idx = 0;
	if (skip != NULL)
		while (line[idx] != '\0' && skip(line[idx]) && !in_set(line[idx]))
			idx++;
	else
		while (line[idx] != '\0' && !in_set(line[idx]))
			idx++;
	if (in_set(line[idx]))
		return (&line[idx]);
	return (NULL);
}
