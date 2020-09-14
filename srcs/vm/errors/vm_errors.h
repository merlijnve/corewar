/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm_errors.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:24:11 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/14 16:41:18 by joris         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_ERRORS_H
# define VM_ERRORS_H

typedef enum e_error	t_error;

enum	e_error
{
	kOk = 0,
	kError = -1,
	kErrParams = -2,
	kErrFile = -3,
	kErrTooManyChamps = -4,
	kErrBadHeader = -11,
	kErrBadSize = -12,
	kErrBadNull = -13,
	kErrCursor = -14,
	kErrOther = -99,
};

void	vm_error(int e, ...);

#endif
