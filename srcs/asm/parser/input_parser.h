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
# define INPUT_PARSER_H

# include "asm.h"

# define BUFF_SIZE 1024

# pragma mark - funcs

t_ret		read_lines(const char *file, t_list **lines);
t_ret		read_file(int fd, char **buffer);
t_ret   	parse_file(t_list *lines, t_asm *asmblr);

t_inst		is_inst(const char *line);
t_line_type	line_type(const char *line);

#endif
