//
//  shared.c
//  cw-asm
//
//  Created by Floris Fredrikze on 06/09/2020.
//

#include <op.h>

// argc			// 1,2,2,3,3,3,3,3,1,3,3,1,2,3,1,1
// dir size		// 4,4,4,4,4,4,4,4,2,2,2,2,4,2,2,4
// timeout		// 10,5,5,10,10,6,6,6,20,25,25,800,10,50,1000,2

static const t_opinfo	g_opinfo[16] =
{
	{.argc = 1, .dir_size = 4, .timeout = 10},
	{.argc = 2, .dir_size = 4, .timeout = 5},
	{.argc = 2, .dir_size = 4, .timeout = 5},
	{.argc = 3, .dir_size = 4, .timeout = 10},
	{.argc = 3, .dir_size = 4, .timeout = 10},
	{.argc = 3, .dir_size = 4, .timeout = 6},
	{.argc = 3, .dir_size = 4, .timeout = 6},
	{.argc = 3, .dir_size = 4, .timeout = 6},
	{.argc = 1, .dir_size = 2, .timeout = 20},
	{.argc = 3, .dir_size = 2, .timeout = 25},
	{.argc = 3, .dir_size = 2, .timeout = 25},
	{.argc = 1, .dir_size = 2, .timeout = 800},
	{.argc = 2, .dir_size = 4, .timeout = 10},
	{.argc = 3, .dir_size = 2, .timeout = 50},
	{.argc = 1, .dir_size = 2, .timeout = 1000},
	{.argc = 1, .dir_size = 4, .timeout = 2},
};

// WARN: do not call code from either ASM or VM here

const t_opinfo *get_opinfo(t_inst intst)
{
	return (&g_opinfo[intst - 1]);
}
