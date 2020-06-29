/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/16 13:25:01 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 16:00:55 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		ft_line_copy(t_list *current, char **line)
{
	int		c;

	c = 0;
	if (ft_strncmp(current->content, "\n", 1) == 0)
	{
		*line = ft_strdup("\0");
		current->content = ft_memmove(current->content, current->content + 1,
		ft_strlen(current->content));
		return (1);
	}
	c = ft_strlchr(current->content, '\n', ft_strlen(current->content));
	if (c == 0)
	{
		*line = ft_strdup(current->content);
		free(current->content);
		current->content = ft_strdup("\0");
		return (1);
	}
	*line = ft_strsub(current->content, 0, c);
	current->content = ft_memmove(current->content, current->content + c + 1,
		ft_strlen(current->content));
	return (1);
}

static int		ft_read_line(t_list *current, const int fd, char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmp;
	int		size;

	size = 1;
	if (ft_strchr(current->content, '\n') == NULL)
	{
		while (size > 0)
		{
			size = read(fd, buf, BUFF_SIZE);
			buf[size] = '\0';
			tmp = ft_strjoin(current->content, buf);
			free(current->content);
			current->content = ft_strdup(tmp);
			free(tmp);
			if (ft_strchr(current->content, '\n'))
				break ;
		}
	}
	if (size == 0 && ft_strlen(current->content) == 0)
		return (0);
	if (size < 0)
		return (-1);
	return (ft_line_copy(current, line));
}

static t_list	*ft_check_fd(t_list **head, int fd)
{
	t_list *list;

	list = *head;
	while (list)
	{
		if ((int)list->content_size == fd)
			return (list);
		list = list->next;
	}
	list = ft_lstnew("\0", fd);
	ft_lstadd(head, list);
	list = *head;
	return (list);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*head;
	t_list			*current;
	char			test[1];

	if (fd < 0 || line == NULL || read(fd, test, 0) < 0)
		return (-1);
	current = ft_check_fd(&head, fd);
	return (ft_read_line(current, fd, line));
}
