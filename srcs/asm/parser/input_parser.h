/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_parser.h                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/11 15:29:15 by floris        #+#    #+#                 */
/*   Updated: 2020/06/11 15:29:26 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_PARSER_H
#define INPUT_PARSER_H

#include <libft.h>
#include "asm.h"

typedef enum e_parse_state	t_parse_state;

enum	e_parse_state
{
	kNoParseState,
	kMetaParseState,
	kNameParseState,
    kCommentParseState,
	kAsmParseState,
};

typedef enum e_parse_flag	t_parse_flag;

enum	e_parse_flag
{
	kNoFlag,
	kLabelFlag,
};

#pragma mark - funcs

t_ret		read_lines(char *file, t_list **lines);
t_ret		read_file(int fd, char **buffer);
t_ret   	parse_file(t_list *lines, t_asm *asmblr);

t_inst		is_inst(char *line);
t_line_type	line_type(char *line);


t_ret		handle_name(t_parse_flag *flag, t_parse_state *state, char *line, t_asm *asmblr);
t_ret		handle_comment(t_parse_flag *flag, t_parse_state *state, char *line, t_asm *asmblr);
t_ret		handle_label(t_parse_flag *flag, t_parse_state *state, char *line, t_asm *asmblr);
t_ret		handle_label(t_parse_flag *flag, t_parse_state *state, char *line, t_asm *asmblr);


#endif
