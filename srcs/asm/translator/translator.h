/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   translator.h                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <libft.h>
#include "asm.h"

t_ret translate(t_list *tokens, t_asm *asmblr, t_error *error);

#pragma mark - instructions

typedef t_ret		(*t_tr_func)(t_asm *, t_tksave *, t_error *);

t_ret 		translate_live(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_ld(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_st(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_add(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_sub(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_and(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_or(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_xor(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_zjmp(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_ldi(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_sti(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_fork(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_lld(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_lldi(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_lfork(t_asm *asmblr, t_tksave parts[], t_error *error);
t_ret 		translate_aff(t_asm *asmblr, t_tksave parts[], t_error *error);

#pragma mark - common

void		put_instruction(t_bytecode *bytecode, t_inst inst);
void		put_encode(t_bytecode *bc, t_enbyte enbyte);
t_ret		put_registry(t_bytecode *bc, unsigned int reg);
t_ret		put_direct(t_asm *asmblr, t_tksave *token, size_t dsize);
t_ret		put_indirect(t_asm *asmblr, t_tksave *token, size_t dsize);

#pragma mark - utils

void		reverse_eb(t_enbyte *eb);
t_ret		asm_regtoint(char *str);
t_args_type	tft(t_asm_token token);
t_ret		put_part(t_asm *asmblr, t_tksave *part, t_inst inst, t_error *error);

#endif



