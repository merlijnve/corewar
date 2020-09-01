/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:24:18 by joris         #+#    #+#                 */
/*   Updated: 2020/09/01 18:54:19 by mvan-eng      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "ft_printf.h"
# include "libft.h"
# include "./errors/errors.h"
# include <ncurses.h>

# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

# define MAGIC_NUMBER_LEN	4

# define HEADER_SIZE		4
# define NULL_SIZE			4
# define CHAMP_FILESIZE		2875

# define DEBUG_ENABLED		0
# define DEBUG_PRINT		1
# define DEBUG_FILE			"debug.log"
# define DEBUG_MAX_CYCLES	42

# define ARG_TYPE_REG		1
# define ARG_TYPE_DIR		2
# define ARG_TYPE_IND		3
# define ARG_TYPE_NONE		0

/*
** Player struct
*/

typedef struct		s_cw_champ_file
{
	uint32_t		magic; // 4
	char			name[PROG_NAME_LENGTH]; // 128
	uint32_t		nt_name; // 4
	uint32_t		size; // 4
	char			comment[COMMENT_LENGTH]; // 2048
	uint32_t		nt_comment; // 4
	// SUB TOTAL: 2192
	char			exec_code[CHAMP_MAX_SIZE]; // 682 % 4 = 2
	// SUB TOTAL: 2874
}					t_cw_champ_file; // TOTAL: 1850 ?
// 2874 % 4 = 2

typedef struct		s_champion
{
	t_cw_champ_file champ;
	int				id;
	int				fd;
	int				argv_index;
	int				mem_index;
	char			*file_name;
}					t_champion;

/** Additional cell information */
typedef struct		s_cell
{
	char			hex;
	bool			taken;
}					t_cell;

/*
**	Argument type can be value of
**	- T_REG = 0x01 = 1
**	- T_DIR = 0x10 = 2
**	- T_IND = 0x11 = 3
**	- empty = 0x00 = 0
*/

typedef struct		s_argument
{
	int				type;
	int				value;
}					t_argument;

/** Individual cursor */
typedef struct		s_cursor
{
	struct s_cursor *next;
	struct s_cursor *prev;
	int				id;
	int				pos;
	int				jump;
	bool			carry;
	int				opcode;
	int				registries[16];
	int				last_alive;
	int				timeout;
	t_argument		args[3];
}					t_cursor;

/** Arena environment */
typedef struct		s_arena
{
	t_cursor		*cursors;

	/** Individual player structs */
	t_champion		champions[MAX_PLAYERS + 1];

	/** Amount of champions **/
	int				champion_count;

	int				cursor_count;

	int				dump_flag;

	int				n_flag;

	/** Individual cell structs **/
	t_cell			cells[MEM_SIZE];

	/** Raw memory array of arena **/
	char			mem[MEM_SIZE];

	/** Current winner player id */
	int				winner_id;

	/** Cycles before we die */
	int				cycles_to_die;

	/** Current count of cycles past */
	int				cycle_count;

	int				current_cycle;

	int				live_count;

	int				last_alive;

	/** Check counter */
	int				check_count;

	/** Operations */
	// op_t op_tab[17];
	/* Visual Window thingys */
	WINDOW			*win;
	WINDOW			*stats;
}					t_arena;

void				print_usage(void);
void				check_args(int argc, char **argv, t_arena *arena);
void				start_arena(t_arena *arena_s);
int					check_champions(t_champion *champions, int champion_count);

int					ft_strntoi(unsigned char *str, int n);
uint32_t			rev_bytes_32(uint32_t value);

void				init_cursors(t_arena *arena_s);

t_cursor			*cursor_create();
t_cursor			*cursor_add(t_cursor **acursor, t_cursor *new);
t_cursor			*cursor_del(t_cursor **acursor, t_cursor *del);
t_cursor			*cursor_clone(t_cursor *origin);

void				debug_print_hex(unsigned char *str, int n);
int					debug_printf(const char *format, ...);
void				debug_print_champion(t_champion *champion);
void				debug_print_cursors(t_cursor *cursors);
int					ft_strntoi(unsigned char *str, int n);
uint32_t			rev_bytes_32(uint32_t value);

void				debug_print_hex(unsigned char *str, int n);
int					debug_printf(const char *format, ...);
void				debug_print_champion(t_champion *champion);
void				debug_print_map(t_arena *arena);
int					is_registry(int arg);
void				add(char *mem, t_cursor *cursor);
void				get_argument_types(char *mem, t_cursor *cursor);
int					get_direct_argument(char *mem, int t_dir_size, int pos);
int					get_pos(int cursor_pos, int pos);
int					read_4_bytes(char *mem, int pos);
void				write_4_bytes(unsigned char *mem, int pos, int value);
int					get_indirect_argument(char *mem, int cursor_pos,
	int arg_pos, bool idx);
void				sub(char *mem, t_cursor *cursor);
void				ld(char *mem, t_cursor *cursor);
void				ldi(char *mem, t_cursor *cursor);
void				lld(char *mem, t_cursor *cursor);
void				lldi(char *mem, t_cursor *cursor);
void				lldi(char *mem, t_cursor *cursor);
void				st(char *mem, t_cursor *cursor);
void				sti(char *mem, t_cursor *cursor);
void				and(char *mem, t_cursor *cursor);
void				or(char *mem, t_cursor *cursor);
void				xor(char *mem, t_cursor *cursor);
void				aff(char *mem, t_cursor *cursor);
void				visual_main(t_arena *arena);
void				update_window(t_arena *arena);

#endif
