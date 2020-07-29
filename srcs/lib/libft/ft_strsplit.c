/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strsplit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 23:05:10 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/07 15:40:27 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	find_word_count(char const *s, char c)
{
	size_t		wcount;

	wcount = 0;
	if (s == NULL || *s == '\0')
		return (0);
	while ((s = ft_strichr(s, c)) != NULL)
	{
		s = ft_strchr(s, c);
		wcount++;
	}
	return (wcount);
}

static char		*get_word(const char *s, char c, t_index idx)
{
	size_t		wcount;

	wcount = 0;
	if (s == NULL || *s == '\0')
		return (NULL);
	while (wcount < idx)
	{
		s = ft_strchr(s, c);
		s = ft_strichr(s, c);
		if (s == NULL)
			return (NULL);
		wcount++;
	}
	return (ft_strndup(s, ft_strclen(s, c)));
}

static char		*check_valid(char const *s, char c)
{
	char	*string;

	string = ft_strctrim(s, c);
	if (string == NULL || *string == '\0')
	{
		free(string);
		return (NULL);
	}
	return (string);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t		wcount;
	char		**list;
	t_index		idx;
	char		*string;

	string = check_valid(s, c);
	if (string == NULL)
		return ((char **)ft_memalloc(sizeof(char *)));
	wcount = find_word_count(string, c);
	if (wcount != 0)
	{
		list = (char **)ft_memalloc(sizeof(char *) * (wcount + 1));
		idx = 0;
		while (list != NULL && idx <= wcount)
		{
			list[idx] = get_word(string, c, idx);
			idx++;
		}
		free(string);
		return (list);
	}
	free(string);
	return (NULL);
}
