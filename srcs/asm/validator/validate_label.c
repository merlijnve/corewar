/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator_label.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 21:24:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/16 21:24:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"
#include "shared_utils.h"

t_ret	validate_label(t_tksave *token, t_error *error)
{
	if (ft_find_chr(token->str, LABEL_CHAR, is_label_chr) == NULL)
	{
		return (set_err_token(token, kErrorBadCharInLabel, error));
	}
	return (kSuccess);
}
