/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdlen.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/24 14:04:36 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:23 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strdlen(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		count++;
		i++;
	}
	return (count);
}
