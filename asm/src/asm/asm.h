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

# include <fcntl.h>
# include <stdio.h>

# include <ft_printf.h>

typedef enum e_ret			t_ret;

// Errors
//  0 -  9 Standart errors
// 10 - 29 Input Erros
// 30 - 39 Algo Errors
//

enum	e_ret
{
	kSuccess = 0,
	kError = -1,
};

/* 
**
*/

typedef struct 		s_asm 
{
	int				n_flags;
}					t_asm;

int		check_args(int argc, char **argv, t_asm *asm_s);

#endif
