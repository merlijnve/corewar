/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/29 16:11:16 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/14 16:29:20 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

# include <libft.h>
# include <ft_printf.h>

typedef uint8_t byte;

typedef enum e_ret			t_ret;
typedef enum e_line_type	t_line_type;
typedef enum e_inst			t_inst;
typedef enum e_args_type	t_args_type;
typedef enum e_asm_token	t_asm_token;


// Errors
//  0 -  9 Standart errors
// 10 - 29 Input Erros
// 30 - 39 Translation Errors
// 40 - 49 Linking errors
//

enum	e_ret
{
	kSuccess = 0,
	kError = -1,
	kErrorAlloc = -2,

	kParseError = -10,

	kInvalidArgumentCount = -30,

	kLinkingError = -40,
};

enum    e_line_type
{
	kUndefinedLine,
	kSourceCommentLine,
	kNameLine,
	kCommentLine,
	kInstLine,
	kInstLabelLine,
	kLabelLine,
	kEmptyLine,
};

enum e_inst
{
    kInstNone = -1,
	kInstLive = 0x01,
	kInstLd = 0x02,
	kInstSt = 0x03,
	kInstAdd = 0x04,
	kInstSub = 0x05,
	kInstAnd = 0x06,
	kInstOr = 0x07,
	kInstXor = 0x08,
	kInstZjmp = 0x09,
	kInstLdi = 0x0A,
	kInstSti = 0x0B,
	kInstFork = 0x0C,
	kInstLld = 0x0D,
	kInstLldi = 0x0E,
	kInstLfork = 0x0F,
	kInstAff = 0x10,
};

enum e_args_type
{
	kTReg = 0b01,
	kTDir = 0b10,
	kTInd = 0b11,
	kTNone = 0b00,
};

enum e_asm_token
{
	kTokenLabel,
	kTokenInstruction,
	kTokenRegister,
	kTokenSeperator,
	kTokenDirectLabel,
	kTokenIndirect,
	kTokenUnknown,
};

typedef struct s_bytecode	t_bytecode;
typedef struct s_asm		t_asm;
typedef struct s_jump		t_jump;
typedef struct s_jump		t_marker;
typedef struct s_enbyte		t_enbyte;
typedef struct s_place		t_place;
typedef struct s_tksave		t_tksave;
typedef struct s_error		t_error;

struct	s_enbyte
{
	t_args_type	arg1 : 2;
	t_args_type	arg2 : 2;
	t_args_type	arg3 : 2;
	t_args_type	empty : 2;
};

struct	s_bytecode
{
	size_t	length;
	byte	*bcpoint;
	byte	*bytecode;
	t_list	*requested;
	t_list	*available;
};

struct	s_asm
{
	int			n_flags;
	char		*name;
	char		*comment;
	t_bytecode	bytecode;
	t_dict		*translator;
	t_list		*jump; // adresses from where a jump needs to be done
	t_list		*marker; // markers to jump to
};

struct	s_jump
{
	char	*label;
	byte	*place;
};

struct	s_place
{
	unsigned int ln;
	unsigned int chr;
};

struct	s_tksave
{
	char *str;
	t_asm_token token;
	t_place	loc;
};

struct s_error
{
	t_ret error;
	t_tksave *token;
};

int		check_args(int argc, char **argv, t_asm *asm_s);

#endif
