/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdcpy.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/18 17:37:12 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:15 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strdcpy(char *dst, const char *src, char c, int i)
{
	int		b;

	b = 0;
	while (src[i] == c && src[i] != '\0')
		i++;
	while (src[i] != c && src[i] != '\0')
	{
		dst[b] = src[i];
		i++;
		b++;
	}
	return (i);
}
