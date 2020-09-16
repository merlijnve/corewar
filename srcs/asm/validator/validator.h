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

t_ret	validate_tokens(t_list *tokens, t_asm *asmblr, t_error *error);

#endif
