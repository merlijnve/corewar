/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   errors.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: wmisiedj <wmisiedj@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/29 15:25:41 by wmisiedj      #+#    #+#                 */
/*   Updated: 2020/08/01 16:55:27 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include <libft.h>
#include <unistd.h>

int 	print_error(const char *format, va_list ap)
{
	return (ft_vdprintf(STDERR_FILENO, format, ap));
}

void vm_error(int e, ...)
{
	va_list ap;
	char    *msg;

	msg = NULL;
	va_start(ap, e);
	if (e == ERR_PARAMS)
		print_usage();
	else if (e == ERR_FILE)
		print_error("Error reading source file %s\n", ap);
	else if (e == ERR_TOO_MANY_CHAMP)
		print_error("Too many champions\n", ap);
	else if (e == ERR_BAD_HEADER)
		print_error("File %s has an invalid header.\n", ap);
	else if (e == ERR_BAD_SIZE)
		print_error("File %s has too large a code.\n", ap);
	else if (e == ERR_BAD_NULL)
		print_error("File %s is not properly formatted with nulls\n", ap);
	else
	{
		msg = va_arg(ap, char *);
		if (msg != NULL)
			ft_dprintf(STDERR_FILENO, "An unknown error occured: %s", msg);
		else 
			print_error("An unknown error occured.", ap);
	}
	va_end(ap);
	exit(EXIT_FAILURE);
}
