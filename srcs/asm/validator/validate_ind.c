/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator_ind.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 21:24:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/16 21:24:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

t_ret	validate_ind(t_tksave *token, t_error *error)
{
	if (token->str == NULL
		|| (ft_strlen(token->str) <= 0)
		|| ((!ft_isdigit(token->str[0]) && token->str[0] != '-'))
		|| (!ft_strisdigit_padd(&token->str[1])))
	{
		return (set_err_token(token, kErrorBadInd, error));
	}
	return (kSuccess);
}
