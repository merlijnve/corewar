/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:24:18 by joris         #+#    #+#                 */
/*   Updated: 2020/07/17 15:51:42 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "ft_printf.h"
# include "libft.h"
# include <stdbool.h>
# include <fcntl.h>
# include <stdlib.h>

# define CHAMP_FILESIZE (16 + PROG_NAME_LENGTH + COMMENT_LENGTH + CHAMP_MAX_SIZE)

# define OK					0
# define ERROR				-1
# define ERROR_BAD_HEADER	-12

/** Head vm struct */
typedef struct		s_vm
{
	int				champ_fd[MAX_PLAYERS];
	int				champ_c;
	int				f_dump;
    int             f_n;
}					t_vm;

/** Player struct */
typedef struct		s_champion
{
    int		id;
	char	bytecode[CHAMP_FILESIZE];
	char	*name;
	char	*comment;
}					t_champion;

/** Additional cell information */
typedef struct s_cell
{
    char hex;
    bool taken;
} t_cell;

/** Individual cursor */
typedef struct s_cursor
{
    struct s_cursor *next;
    struct s_cursor *prev;
    int id;
    int pos;
    bool carry;
    int opcode;
} t_cursor;

/** Arena environment */
typedef struct s_arena
{
    /** Linked list of cursors */
    t_cursor *cursors;

    /** Individual player structs */
    t_champion champions[MAX_PLAYERS + 1];

    /** Amount of players */
    int player_count;

    /** Individual cell structs */
    t_cell cells[MEM_SIZE];

    /** Raw memory array of arena */
    char mem[MEM_SIZE];

    /** Current winner player id */
    int winner_id;

    /** Cycles before we die */
    int cycles_to_die;

    /** Current count of cycles past */
    int cylces_count;

    /** Check counter */
    int check_count;

    /** Operations */
    //op_t op_tab[17];
} t_arena;

int			check_args(int argc, char **argv, t_vm *vm_s);

#endif