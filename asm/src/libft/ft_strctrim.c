/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strctrim.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/09 17:45:20 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:26 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_index	find_start(char const *s, char c)
{
	t_index		idx;

	idx = 0;
	while (s[idx] == c)
		idx++;
	return (idx);
}

static t_index	find_end(char const *s, char c)
{
	size_t		len;
	t_index		idx;

	len = ft_strlen(s);
	idx = len - 1;
	while (s[idx] == c)
		idx--;
	return (idx);
}

char			*ft_strctrim(char const *s, char c)
{
	t_index start;
	t_index end;
	char	*dest;

	if (*s == '\0')
		return (ft_strdup(s));
	start = find_start(s, c);
	if (start == ft_strlen(s))
		return (ft_strdup(""));
	end = find_end(s, c);
	if (end < start)
		return (ft_strdup(""));
	dest = ft_strndup(&s[start], end - start + 1);
	return (dest);
}
