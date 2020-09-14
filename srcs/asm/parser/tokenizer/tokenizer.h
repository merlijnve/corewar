/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "error.h"
# include "token_types.h"

t_ret tokens_from_lines(t_list *lines, t_list **tokens, t_index skiplines);
t_ret add_token(t_list **tokens, t_tksave *token);

# pragma mark - tokenizers

t_ret tk_inst_line(char *line, t_place loc, t_list **tokens);
t_ret tk_inst_label_line(char *line, t_place loc, t_list **tokens);
t_ret tk_label_line(char *line, t_place loc, t_list **tokens);
t_ret tk_args_line(char *line, t_place loc, t_list **tokens);

# pragma mark - tokenizer common

t_tksave *get_reg(char *line, t_place *loc);

t_ret	get_tk_for_inst(char *line, t_tksave *token, t_place *loc);
t_ret	get_tk_for_label(char *line, t_tksave *token, t_place *loc);
t_ret	get_tk_for_reg(char *line, t_tksave *token, t_place *loc);
t_ret	get_tk_for_ind(char *line, t_tksave *token, t_place *loc);
t_ret	get_tk_for_dir(char *line, t_tksave *token, t_place *loc);
t_ret	get_tk_for_sep(char *line, t_tksave *token, t_place *loc);

#endif
