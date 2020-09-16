/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   token_types.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 22:17:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 22:17:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_TYPES_H
# define TOKEN_TYPES_H

typedef enum e_asm_token	t_asm_token;

enum	e_asm_token
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

#endif
