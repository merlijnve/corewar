/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   metaparse.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef METAPARSE_H
# define METAPARSE_H

# include "asm.h"

t_ret	get_meta_from_file
	(const char *file, t_asm *asmblr, t_error *error, t_index *lines);

#endif
