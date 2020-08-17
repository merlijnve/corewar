/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:24:11 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/08/13 15:16:12 by merlijn       ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CW_VM_ERROR_H
# define FT_CW_VM_ERROR_H

# define OK 0
# define ERROR -1

# define ERR_PARAMS -2
# define ERR_FILE -3
# define ERR_TOO_MANY_CHAMP -4

# define ERR_BAD_HEADER -11
# define ERR_BAD_SIZE -12
# define ERR_BAD_NULL -13

# define ERR_OTHER -99

void    vm_error(int e, ...);

#endif
