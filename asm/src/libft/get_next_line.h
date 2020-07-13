/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/06 16:39:38 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/11 20:13:43 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 2048

typedef enum e_return		t_return;

enum	e_return {
	kHasMore = 2,
	kEndLine = 1,
	kNoRead = 0,
	kError = -1,
};

int			read_from_cache(const int fd, char **line, t_dict *cache);
int			read_from_file(const int fd, t_dict *cache);
void		update_cache(char **str, size_t take_len);
t_return	read_file(ssize_t *lr, size_t *rb, char *buff, int fd);

#endif
