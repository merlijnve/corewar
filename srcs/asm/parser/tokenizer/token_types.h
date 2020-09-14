//
//  token_types.h
//  cw-asm
//
//  Created by Floris Fredrikze on 14/09/2020.
//

#ifndef token_types_h
#define token_types_h

typedef enum e_asm_token	t_asm_token;

enum e_asm_token
{
	kTokenNone = 0,
	kTokenLabel,
	kTokenInstruction,
	kTokenRegister,
	kTokenSeperator,
	kTokenDir,
	kTokenDirLabel,
	kTokenInd,
	kTokenIndLabel,
	kTokenUnknown,
};

typedef struct s_place		t_place;

struct	s_place
{
	t_index ln;
	t_index chr;
};

typedef struct s_tksave		t_tksave;

struct	s_tksave
{
	char		*str;
	t_asm_token	token;
	t_place		loc;
};

#endif /* token_types_h */
