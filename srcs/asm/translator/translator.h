#ifndef TRANSLATOR_H
#define TRANSLATOR_H

#include <libft.h>
#include "asm.h"

#pragma mark - instructions

t_ret translate_live(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_ld(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_st(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_add(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_sub(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_and(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_or(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_xor(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_zjmp(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_ldi(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_sti(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_fork(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_lld(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_lldi(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_lfork(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);
t_ret translate_aff(t_asm *asmblr, int partc, t_tksave parts[], t_error *error);

#pragma mark - common

void put_instruction(t_bytecode *bytecode, t_inst inst);
void put_encode(t_bytecode *bc, t_enbyte enbyte);
t_ret put_registry(t_bytecode *bc, unsigned int reg);
t_ret put_direct(t_asm *asmblr, char* direct);

#pragma mark - utils

t_ret asm_regtoint(char *str);
t_args_type tft(t_asm_token token);
t_ret put_part(t_asm *asmblr, t_tksave *part, t_error *error);

#endif



