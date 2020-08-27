/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tokenizer.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/08/27 13:01:20 by floris        #+#    #+#                 */
/*   Created: 2020/08/27 13:01:20 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "tokenizer.h"

t_ret	get_tokens_from_file(char *file, t_list *tokens, int startln, t_error *error)
{
	t_ret ret;

	ret = kSuccess;

	error->error = ret;
	return (ret);
}

t_ret	get_tokens_from_labelline(char *line, t_list *tokens, int lnum, t_error *error)
{
//	char *parts[];

	return (kSuccess);

}

t_ret	get_tokens_from_instline(char *line, t_list *tokens, int lnum, t_error *error)
{
//	char *parts[];

//	parts = ft_strsplit(line, )

	return (kSuccess);

}

