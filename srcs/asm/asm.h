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

#ifndef ASM_H
# define ASM_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

# include <libft.h>
# include <ft_printf.h>
# include <op.h>

# include "tokenizer.h"

typedef uint8_t				t_byte;

typedef enum e_line_type	t_line_type;

enum	e_line_type
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

typedef struct s_bytecode	t_bytecode;
typedef struct s_asm		t_asm;
typedef struct s_jump		t_jump;
typedef struct s_jump		t_marker;

struct	s_bytecode
{
	size_t	length;
	t_byte	*bcp;
	t_byte	*bcdata;
	t_index	last_inst;
	t_list	*jump;
	t_list	*marker;
};

struct	s_asm
{
	int			n_flags;
	char		name[PROG_NAME_LENGTH + 2];
	bool		has_name;
	char		comment[COMMENT_LENGTH + 2];
	bool		has_comment;
	t_bytecode	bc;
	char		*file;
	t_list		*lines;
	t_list		*tokens;
	const char	*file_name;
};

struct	s_jump
{
	t_tksave	*token;
	t_index		idx;
	t_index		ins_idx;
	t_args_type	type;
};

#endif
