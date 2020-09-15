/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_args.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-eng <mvan-eng@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/08 15:48:04 by mvan-eng      #+#    #+#                 */
/*   Updated: 2020/07/08 21:24:45 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include "asm.h"

void	exit_check_args(char *argv[], char *argv_s[], t_ret signal)
{
	if (signal == kError)
	{
		if (argv != argv_s)
			free(argv_s);
		exit(EXIT_FAILURE);
	}
	else if (argv != argv_s)
		free(argv_s);
}

int		count_strings(char **argv, char *s)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], s) == 0)
			count++;
		i++;
	}
	return (count);
}

char	**strip_flags(int argc, char *argv[], t_asm *asm_s)
{
	int		i;
	int		j;
	int		n_flags;
	char	**argv_s;

	i = 0;
	j = 0;
	n_flags = count_strings(argv, "-a");
	argv_s = ft_memalloc(sizeof(char *) * (argc - n_flags));
	asm_s->n_flags = n_flags;
	while (argv[i] != NULL)
	{
		if (ft_strcmp(argv[i], "-a") != 0)
		{
			argv_s[j] = argv[i];
			j++;
		}
		i++;
	}
	return (argv_s);
}

int		check_args(int argc, char *argv[], t_asm *asmblr)
{
	int		input_fd;
	char	**argv_s;

	argv_s = strip_flags(argc, argv, asmblr);
	if (argc - asmblr->n_flags == 1)
	{
		ft_printf("Usage: %s [-a] <sourcefile.s>\n"
				  "\t-a : Instead of creating a .cor file, outputs a stripped"
				  " and annotated version of the code to the standard output\n", argv[0]);
		exit_check_args(argv, argv_s, kError);
	}
	input_fd = open(argv_s[argc - asmblr->n_flags - 1], O_RDONLY);
	asmblr->file_name = argv_s[argc - asmblr->n_flags - 1];
	if (input_fd == -1)
	{
		perror(argv_s[argc - asmblr->n_flags - 1]);
		exit_check_args(argv, argv_s, kError);
	}
	exit_check_args(argv, argv_s, kSuccess);
	return (input_fd);
}
