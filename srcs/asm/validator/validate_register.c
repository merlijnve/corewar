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

static int	ft_strisdigit_padd(const char *s)
{
	t_index idx;

	idx = 0;
	while (s[idx] != '\0' && !ft_isspace(s[idx]))
	{
		if (!ft_isdigit(s[idx]))
			return (0);
		idx++;
	}
	return (1);
}

t_ret		validate_register(t_tksave *token, t_error *error)
{
	if (token->str == NULL
		|| (token->str[0] != REGISTER_CHAR)
		|| (ft_strlen(token->str) <= 1)
		|| (!ft_strisdigit_padd(&token->str[1])))
	{
		return (set_err_token(token, kErrorBadRegister, error));
	}
	return (kSuccess);
}
