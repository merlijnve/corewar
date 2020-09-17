/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator_register.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 21:24:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/16 21:24:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

#include "shared_utils.h"

/*
** check if reg is not 0
** || (ft_atoi(&token->str[1]) == 0))
*/

t_ret		validate_register(t_tksave *token, t_error *error)
{
	if (token->str == NULL
		|| (token->str[0] != REGISTER_CHAR)
		|| (ft_strlen(token->str) <= 1)
		|| (!ft_strisdigit_padd(&token->str[1]))
		|| (ft_atoi(&token->str[1]) <= 0)
		|| (ft_atoi(&token->str[1]) >= 100))
	{
		return (set_err_token(token, kErrorBadRegister, error));
	}
	return (kSuccess);
}
