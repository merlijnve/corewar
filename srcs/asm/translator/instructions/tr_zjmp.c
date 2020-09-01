/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_zjump.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_zjmp(t_asm *asmblr, t_tksave parts[], t_error *error)
{
	put_instruction(&asmblr->bytecode, kInstZjmp);
	return (put_part(asmblr, &parts[0], kInstZjmp, error));
}
