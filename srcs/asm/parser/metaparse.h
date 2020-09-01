/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   metaparse.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef METAPARSE_H
#define METAPARSE_H

#include "asm.h"

t_ret	get_meta_from_file(t_list *lines, t_tksave tokens[2], t_error *error);

#endif
