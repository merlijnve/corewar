/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cursor_util.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/14 15:26:56 by joris         #+#    #+#                 */
/*   Updated: 2020/09/16 02:44:24 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		cursor_jump(t_cursor *current, t_enbyte enbyte)
{
	if (current->jump == 0)
	{
		current->jump = args_length(enbyte, current->opcode);
	}
}
