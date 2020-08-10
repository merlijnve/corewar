/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/30 19:22:32 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/08/09 17:41:01 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */


#include "vm.h"

uint32_t rev_bytes_32(uint32_t value)
{
     return (value & 0x000000FFU) << 24 | (value & 0x0000FF00U) << 8 |
         (value & 0x00FF0000U) >> 8 | (value & 0xFF000000U) >> 24;
}

// static int  char_base(int c, int base)
// {
//     int i;

//     i = 0;
// 	while (i < base)
// 	{
// 		if (ft_tolower(c) == "0123456789abcdef"[i])
// 			return (i);
// 		i++;
// 	}

// 	return (-1);
// }

int     ft_strntoi(unsigned char *str, int n)
{
    unsigned char    *start;
    int     total;
    int     i;

    i = 0;
    total = 0;
    start = str;
    ft_printf("DATA: '%s'\n", str);
    while (i < n)
    {
        ft_printf("Checking: (%d) %d\n", i, start[i]);
        total *= 2;
        if (start[i] == '1')
            total += 1;
        i++;
    }

    return (total);
}
