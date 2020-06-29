/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strcmp.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/08 17:19:43 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:06 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int x;

	x = 0;
	while (s1[x] != '\0' && s2[x] != '\0' && (s1[x] == s2[x]))
		x++;
	return (((unsigned char)s1[x]) - ((unsigned char)s2[x]));
}
