/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   debugging.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 15:29:33 by floris        #+#    #+#                 */
/*   Updated: 2020/06/11 15:29:35 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef debugging_h
#define debugging_h

#include "asm.h"

void	print_file(char *file);
void	print_lines(t_list *lines);
void	print_tokens(t_list *lines);
void	print_bc(t_asm *asmblr, size_t size);
void	debug_print_mem(const void *addr, size_t size);

#endif
