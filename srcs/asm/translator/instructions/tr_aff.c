/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tr_aff.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Updated: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "translator.h"

t_ret	translate_aff(t_asm *asmblr, t_tksave parts[], t_error *error)
{
	put_instruction(&asmblr->bc, kInstAff);
	put_encode(&asmblr->bc, (t_enbyte){kTReg, kTNone, kTNone, kTNone});
	return (put_part(asmblr, &parts[0], kInstAdd, error));
}
