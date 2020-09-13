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
# include <op.h>

typedef uint8_t 			t_byte;

typedef enum e_ret			t_ret;
typedef enum e_line_type	t_line_type;
typedef enum e_asm_token	t_asm_token;


void	debug_print_mem(const void *addr, size_t size); // TODO: remove

// Errors
//  0 -  9 Standart errors
// 10 - 29 Input Erros
// 30 - 39 Translation Errors
// 40 - 49 Linking errors
// 50 - 69 Token errors
//

enum	e_ret
{
	kSuccess = 0,
	kError = -1,
	kErrorAlloc = -2,
	kErrorOpeningFile = -3,

	kInputError = -10,
	kParseError = -11,

	kTranslationError = -30,
	kInvalidArgumentCount = -31,

	kLinkingError = -40,
	kLinkNotFoundError = -41,

	kTokenError = -50,

	kMetaParseError = -60,
	kMPNameTooLong = -61,
	kMPCommentTooLong = -62,
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

typedef struct s_bytecode	t_bytecode;
typedef struct s_asm		t_asm;
typedef struct s_jump		t_jump;
typedef struct s_jump		t_marker;
typedef struct s_place		t_place;
typedef struct s_tksave		t_tksave;
typedef struct s_error		t_error;

struct	s_bytecode
{
	size_t	length;
	t_byte	*bcpoint;
	t_byte	*bytecode;
	t_index	last_inst;
	t_list	*jump; // adresses from where a jump needs to be done
	t_list	*marker; // markers to jump to
};

struct	s_asm
{
	int			n_flags;
	char		name[PROG_NAME_LENGTH + 2];
	char		comment[COMMENT_LENGTH + 2];
	t_bytecode	bytecode;
	char 		*file;
	t_list 		*lines;
	t_list 		*tokens;
};

struct	s_jump
{
	t_tksave	*token;
	t_index		idx;
	t_index		ins_idx;
	t_args_type	type;
};

struct	s_place
{
	t_index ln;
	t_index chr;
};

struct	s_tksave
{
	char		*str;
	t_asm_token	token;
	t_place		loc;
};

struct s_error
{
	t_ret		code;
	t_tksave	*token;
	t_tksave	rtoken;
};

#endif
