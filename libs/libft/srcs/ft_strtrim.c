/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 15:18:29 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 16:00:36 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void	ft_justworkalready(int i, int end, char *str, char const *s)
{
	int b;

	b = 0;
	while (i < end)
	{
		str[b] = s[i];
		b++;
		i++;
	}
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		end;

	if (s == NULL)
		return (NULL);
	end = (int)ft_strlen(s);
	i = 0;
	while ((s[i] == ' ' || s[i] == '\n' || s[i] == '\t') && s[i] != '\0')
		i++;
	while ((s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
	&& end != 0)
		end--;
	if ((end - i) < 1)
		str = ft_strnew(1);
	else
		str = ft_strnew(end - i);
	if (str == NULL)
		return (NULL);
	ft_justworkalready(i, end, str, s);
	return (str);
}
