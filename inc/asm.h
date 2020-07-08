/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/29 16:11:16 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/08 18:40:36 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libs/ft_printf/includes/ft_printf.h"
# include <fcntl.h>
# include <stdio.h>

# define OK 0
# define ERROR -1

/* 
**
*/

typedef struct 		s_asm 
{
	int				n_flags;
}					t_asm;

int		check_args(int argc, char **argv, t_asm *asm_s);

#endif
