/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_fork.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret translate_fork(t_asm *asmblr, t_tksave parts[], t_error *error)
{
	put_instruction(&asmblr->bytecode, kInstFork);
	return (put_part(asmblr, &parts[0], kInstFork, error));
}
