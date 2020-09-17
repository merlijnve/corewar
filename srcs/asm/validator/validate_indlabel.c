/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator_indlabel.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 21:24:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/16 21:24:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

t_ret	validate_indlabel(t_tksave *token, t_error *error)
{
	if (token->str == NULL
		|| (ft_strlen(token->str) <= 1)
		|| (token->str[0] != LABEL_CHAR))
	{
		return (set_err_token(token, kErrorBadIndLabel, error));
	}
	return (kSuccess);
}
