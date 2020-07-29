/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_print_functions.c                              :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:48 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:08 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include "ft_print_functions.h"

# ifdef LINUX
#  define MY_FILENO _file;
# else
#  define MY_FILENO _fileno;
# endif

static t_pf_ret		print_buffer(t_pf_buffer *buff, size_t len, t_pf_obj *obj)
{
	int ret;
	int fd;

	ret = PF_RET_ERROR;
	if (obj->dtype == PRINT_DEST_FIDES)
		ret = (write(obj->dest.fd, buff->data, len) >= 0
				? PF_RET_SUCCESS : PF_RET_WRITE_ERROR);
	else if (obj->dtype == PRINT_DEST_STREAM)
	{
		fd = obj->dest.file->MY_FILENO;
		if (fd >= 0)
			ret = (write(fd, buff->data, len) >= 0
				? PF_RET_SUCCESS : PF_RET_WRITE_ERROR);
		else
			ret = PF_RET_WRITE_ERROR;
	}
	return (ret);
}

static t_pf_ret		update_buffer
	(size_t *added_bytes, t_pf_buffer *buff, size_t len, const char *str)
{
	long long		lens;
	char			*buffer;

	buffer = (char *)buff->data;
	lens = ft_min(LOCAL_BUFFER_SIZE - buff->idx, len - *added_bytes);
	ft_memcpy(&buffer[buff->idx], &str[*added_bytes], lens);
	*added_bytes += lens;
	buff->idx += lens;
	return (PF_RET_SUCCESS);
}

static t_pf_ret		write_to_buffer(const char *str, size_t len, t_pf_obj *obj)
{
	static t_pf_buffer	buff;
	size_t				added_bytes;
	t_pf_ret			ret;

	ret = PF_RET_SUCCESS;
	added_bytes = 0;
	if (str == NULL)
	{
		ret = print_buffer(&buff, buff.idx, obj);
		buff.idx = 0;
		return (ret);
	}
	while (added_bytes < len && ret == PF_RET_SUCCESS)
	{
		if (buff.idx < LOCAL_BUFFER_SIZE)
			update_buffer(&added_bytes, &buff, len, str);
		else
		{
			ret = print_buffer(&buff, LOCAL_BUFFER_SIZE, obj);
			buff.idx = 0;
		}
	}
	return (ret);
}

t_pf_ret			print(const char *str, ssize_t n, t_pf_obj *obj)
{
	if (str == NULL && n == 0)
		return (write_to_buffer(str, n, obj));
	if (n == LEN_NS || n < 0)
		n = ft_strlen(str);
	if (write_to_buffer(str, n, obj) >= 0)
	{
		obj->chr_wrtn += n;
		return (PF_RET_SUCCESS);
	}
	return (PF_RET_WRITE_ERROR);
}
