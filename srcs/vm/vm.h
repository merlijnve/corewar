/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:24:18 by joris         #+#    #+#                 */
/*   Updated: 2020/07/29 21:08:43 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "ft_printf.h"
# include "libft.h"
# include "./errors/errors.h"

# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>

# define DEBUG_FILE                 "debug.log"
# define CHAMP_FILESIZE             (16 + PROG_NAME_LENGTH + COMMENT_LENGTH \
+ CHAMP_MAX_SIZE)
# define OK                         0
# define ERROR                      -1
# define ERROR_BAD_HEADER           -12
# define ERROR_BAD_SIZE             -13
# define ERROR_BAD_NULL             -14

/** Player struct */
typedef struct      s_champion
{
    int				id;
	int				fd;
	int				argv_index;
    char			bytecode[CHAMP_FILESIZE];
	char			*file_name;
    unsigned char	*name;
    unsigned char	*comment;
    unsigned char	*exec_code;
    size_t			exec_code_size;
}                   t_champion;

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
	
	/** Amount of champions */
    int 		champion_count;

	int			dump_flag;

	int			n_flag;

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
    // op_t op_tab[17];
} t_arena;

void		    print_usage(void);
void			check_args(int argc, char **argv, t_arena *arena);
void            start_arena(t_arena *arena_s);
#endif
