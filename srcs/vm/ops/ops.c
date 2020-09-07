//
//  ops.c
//  cw-asm
//
//  Created by Floris Fredrikze on 06/09/2020.
//

#include "vm.h"

static const t_op_func g_op_funcs[17] =
{
	NULL,
	inst_live,
	inst_ld,
	inst_st,
	inst_add,
	inst_sub,
	inst_and,
	inst_or,
	inst_xor,
	inst_zjmp,
	inst_ldi,
	inst_sti,
	inst_fork,
	inst_lld,
	inst_lldi,
	inst_lfork,
	inst_aff
};

t_op_func get_op_func(t_inst inst)
{
	if (is_opcode(inst))
		return (g_op_funcs[inst]);
	return (NULL);
};
