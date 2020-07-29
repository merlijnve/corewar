/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstfreeone.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: ffredrik <ffredrik@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/08 13:59:26 by ffredrik      #+#    #+#                 */
/*   Updated: 2019/02/08 14:19:52 by ffredrik      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstfreeone(t_list **alst)
{
	free((*alst)->content);
	free(*alst);
	*alst = NULL;
}
