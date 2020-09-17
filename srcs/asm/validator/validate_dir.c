/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   validator_dir.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/16 21:24:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/16 21:24:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "validator.h"

t_ret	validate_dir(t_tksave *token, t_error *error)
{
	if (token->str == NULL
		|| (ft_strlen(token->str) <= 1)
		|| (token->str[0] != DIRECT_CHAR)
		|| ((!ft_isdigit(token->str[1]) && token->str[1] != '-'))
		|| (!ft_strisdigit_padd(&token->str[2])))
	{
		return (set_err_token(token, kErrorBadDir, error));
	}
	return (kSuccess);
}
