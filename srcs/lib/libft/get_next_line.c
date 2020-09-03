/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 16:39:38 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/11 20:48:31 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "get_next_line.h"

int			get_next_line(const int fd, char **line)
{
	static t_dict	*cache;
	t_dict			*curd;
	t_return		rc;
	char			*curs;

	if (fd < 0)
		return (-1);
	curs = NULL;
	if (cache == NULL)
		cache = ft_dictnew();
	rc = kHasMore;
	while (rc == kHasMore && cache)
	{
		curd = ft_dictget(cache, fd);
		if (curd && curd->pair->value)
			rc = read_from_cache(fd, &curs, cache);
		else
			rc = read_from_file(fd, cache);
	}
	if (!curs)
		return (((rc == kError) || cache == NULL) ? -1 : 0);
	*line = ft_strctrim(curs, '\n');
	free(curs);
	return ((rc == kEndLine) ? 1 : 0);
}

int			read_from_cache(const int fd, char **line, t_dict *cache)
{
	t_dict			*curd;
	char			*cstr;
	char			*lline;
	size_t			clen;
	size_t			llen;

	curd = ft_dictget(cache, fd);
	cstr = (char *)curd->pair->value;
	clen = ft_strclen(cstr, '\n') + (cstr[ft_strclen(cstr, '\n')] == '\n');
	llen = (*line != NULL) ? ft_strlen(*line) : 0;
	lline = ft_memalloc(clen + llen + 1);
	if (*line != NULL)
	{
		ft_strncpy(lline, *line, llen);
		ft_strncpy(lline + llen, cstr, clen);
	}
	else
		ft_strncpy(lline, cstr, clen);
	free(*line);
	*line = lline;
	update_cache((char **)&(curd->pair->value), clen);
	if (ft_strclen(lline, '\n') != ft_strlen(lline))
		return (kEndLine);
	else
		return (kHasMore);
}

int			read_from_file(const int fd, t_dict *cache)
{
	char		*buff;
	ssize_t		last_read;
	t_dict		*curd;
	t_return	rc;

	rc = kHasMore;
	buff = (char *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	last_read = read(fd, buff, BUFF_SIZE);
	if (last_read < 0)
		rc = kError; // TODO: correct error
	if (last_read == 0 && rc != kError)
		rc = kEndLine;
	curd = ft_dictget(cache, fd);
	if (!curd && rc == kHasMore)
		ft_dictadd(cache, fd, buff);
	else if (rc == kHasMore)
		curd->pair->value = buff;
	if (rc != kHasMore)
		free(buff);
	return (rc);
}

void		update_cache(char **str, size_t taken_len)
{
	size_t	len;
	size_t	new_len;
	char	*new;

	len = ft_strlen(*str);
	if (taken_len >= len)
	{
		free(*str);
		*str = NULL;
	}
	else
	{
		new_len = len - taken_len;
		new = (char *)ft_memalloc(new_len + 1);
		if (new)
			ft_strncpy(new, *str + taken_len, new_len);
		free(*str);
		*str = new;
	}
}
