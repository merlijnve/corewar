/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdcount.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 12:17:09 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:59:12 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_strdcount(char const *s, char c)
{
	int i;
	int count;
	int temp;

	temp = 0;
	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			i++;
			temp = 1;
		}
		while (s[i] == c && s[i] != '\0')
			i++;
		count++;
	}
	if (temp == 1)
		return (count);
	return (0);
}
