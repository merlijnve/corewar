/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   champions.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/10 21:39:36 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/09/10 22:57:27 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

# include "vm.h"

t_champion	*champion_find_id(t_arena *arena, int id)
{
	int		i;

	i = 0;
	while (i < MAX_PLAYERS)
	{
		if (arena->champions[i].id == id)
			return (&arena->champions[i]);
		i++;
	}
	return (NULL);
}