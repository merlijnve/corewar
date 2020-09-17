/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator_dirlabel.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 21:24:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/16 21:24:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

t_ret	validate_dirlabel(t_tksave *token, t_error *error)
{
	if (token->str == NULL
		|| (ft_strlen(token->str) <= 2)
		|| (token->str[0] != DIRECT_CHAR)
		|| (token->str[1] != LABEL_CHAR))
	{
		return (set_err_token(token, kErrorBadDirLabel, error));
	}
	return (kSuccess);
}
