/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_digitc.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/19 17:37:07 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/04/14 15:56:12 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int		ft_digitc(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}
