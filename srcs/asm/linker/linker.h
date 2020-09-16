/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   linker.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 22:17:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 22:17:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINKER_H
# define LINKER_H

# include "asm.h"

t_ret	asm_link(t_asm *asmblr, t_error *error);

#endif
