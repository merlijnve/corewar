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
# include <ft_printf.h>

typedef enum e_ret			t_ret;
typedef enum e_line_type	t_line_type;
typedef enum e_inst			t_inst;

// Errors
//  0 -  9 Standart errors
// 10 - 29 Input Erros
// 30 - 39 Linking errors
//

enum	e_ret
{
	kSuccess = 0,
	kError = -1,
	kErrorAlloc = -2,

	kParseError = -10,

	kLinkingError = -30,
};

enum    e_line_type
{
	kUndefinedLine,
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
	kInstLive,
	kInstLd,
	kInstSt,
	kInstAdd,
	kInstSub,
	kInstAnd,
	kInstOr,
	kInstXor,
	kInstZjmp,
	kInstLdi,
	kInstSti,
	kInstFork,
	kInstLld,
	kInstLldi,
	kInstLfork,
	kInstAff,
};

typedef struct s_bytecode	t_bytecode;
typedef struct s_asm		t_asm;
typedef struct s_jump		t_jump;

struct	s_bytecode
{
	size_t	length;
	char	*bytecode;
	t_list	*requested;
	t_list	*available;
};

struct	s_asm
{
	int			n_flags;
	char		*name;
	char		*comment;
	t_bytecode	bytecode;
};

struct	s_jump
{
	char	*label;
	char	*place;
};

int		check_args(int argc, char **argv, t_asm *asm_s);

#endif
