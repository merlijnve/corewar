/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_file.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/08 14:41:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/08 14:41:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_FILE_H
#define WRITE_FILE_H

#include "asm.h"

t_ret	write_file(t_asm *asmblr, int fd, t_error *error);

#endif
