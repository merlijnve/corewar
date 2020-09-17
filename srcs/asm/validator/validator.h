/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 22:17:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 22:17:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATOR_H
# define VALIDATOR_H

# include "asm.h"

typedef t_ret	(*t_vl_func)(t_tksave *token, t_error *error);

t_inst	is_inst(const char *line);
bool	ft_strisdigit_padd(const char *s);

t_ret	validate_tokens(t_list *tokens, t_asm *asmblr, t_error *error);

t_ret	validate_label(t_tksave *token, t_error *error);
t_ret	validate_instruction(t_tksave *token, t_error *error);
t_ret	validate_register(t_tksave *token, t_error *error);

t_ret	validate_none(t_tksave *token, t_error *error);
t_ret	validate_label(t_tksave *token, t_error *error);
t_ret	validate_instruction(t_tksave *token, t_error *error);
t_ret	validate_register(t_tksave *token, t_error *error);
t_ret	validate_dir(t_tksave *token, t_error *error);
t_ret	validate_dirlabel(t_tksave *token, t_error *error);
t_ret	validate_ind(t_tksave *token, t_error *error);
t_ret	validate_indlabel(t_tksave *token, t_error *error);

t_ret	validate_args(t_list *tkns, t_inst inst, t_error *error);

#endif
