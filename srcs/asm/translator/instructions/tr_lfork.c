/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_lfork.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_lfork(t_asm *asmblr, int partc, t_tksave parts[], t_error *error)
{
	put_instruction(&asmblr->bytecode, kInstLfork);
	return (put_part(asmblr, &parts[0], kInstLfork, error));
}
