/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: joris <joris@student.codam.nl>               +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/13 17:24:18 by joris         #+#    #+#                 */
/*   Updated: 2020/09/11 13:25:50 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <sys/time.h>
# include <ncurses.h>

# include <stdbool.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <stdint.h>

# include "op.h"
# include "ft_printf.h"
# include "libft.h"
# include "errors.h"

# define MAGIC_NUMBER_LEN	4
# define ARGS_MAX			3

# define HEADER_SIZE		4
# define NULL_SIZE			4
# define CHAMP_FILESIZE		2875

# define DEBUG_ENABLED		0
# define DEBUG_PRINT		0
# define DEBUG_FILE			"debug.log"
# define DEBUG_MAX_CYCLES	0

# define VISUAL_TIMEOUT		35000
# define VISUAL_FPS			30
# define VISUAL_WIDTH		204

# define ARG_TYPE_REG		1
# define ARG_TYPE_DIR		2
# define ARG_TYPE_IND		3
# define ARG_TYPE_NONE		0

# define KEY_SPACE			32
# define KEY_ESC			27

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


/*
**	Argument type can be value of
**	- T_REG = 0x01 = 1
**	- T_DIR = 0x10 = 2
**	- T_IND = 0x11 = 3
**	- empty = 0x00 = 0
*/

typedef struct		s_argument
{
	t_args_type		type;
	int32_t			value;
}					t_argument;


/** Individual cursor */

typedef struct s_cursor	t_cursor;

struct		s_cursor
{
	t_cursor 		*next;
	int				id;
	long			pos;
	int				jump;
	bool			carry;
	t_inst			opcode;
	int				registries[16];
	int				last_alive;
	int				timeout;
	t_argument		args[3];
};

typedef struct		s_cell
{
	t_cursor		*cursor;
	char			hex;
	bool			taken;
}					t_cell;

typedef struct		s_visualizer
{
	bool			enabled;
	WINDOW			*arena;
	WINDOW			*stats;
	int				sleep;
	double			updated_ms;
}					t_visualizer;

/** Arena environment */
typedef struct		s_arena
{
	t_cursor		*cursors;

	/** Individual player structs */
	t_champion		champions[MAX_PLAYERS + 1];

	/** Amount of champions **/
	int				champion_count;

	int				cursor_count;
	int				cursors_active;

	int				dump_flag;

	int				n_flag;

	/** Individual cell structs **/
	t_cell			cells[MEM_SIZE + 1];

	/** Raw memory array of arena **/
	uint8_t			mem[MEM_SIZE + 1];

	/** Current winner player id */
	t_champion		*winner;

	/** Cycles before we die */
	int				cycles_to_die;

	/** Current count of cycles past */
	int				cycle_count;

	int				cycles_since_check;

	int				live_count;

	/** Check counter */
	int				check_count;

	t_visualizer	visualizer;
	/** Operations */
	// op_t op_tab[17];
}					t_arena;

void				print_usage(void);
void				check_args(int argc, char **argv, t_arena *arena);
void				dump(uint8_t *mem);

void				vm_start(t_arena *arena_s);
bool				vm_run_cycle(t_arena *arena_s);

int					check_champions(t_champion *champions, int champion_count);
t_champion			*champion_find_id(t_arena *arena, int id);

int					init_cursors(t_arena *arena_s);

t_cursor 			*cursor_add(t_arena *arena, t_cursor *clone);
void        		cursor_del(t_arena *arena, int id);
void        		cursor_setpos(t_arena *arena, t_cursor *cursor, long pos);
int					cursor_get_pid(t_cursor *cursor);
	
void				debug_print_hex(unsigned char *str, int n);
int					debug_printf(const char *format, ...);
void				debug_print_champion(t_champion *champion);
void				debug_print_cursors(t_cursor *cursors);

void				debug_print_hex(unsigned char *str, int n);
int					debug_printf(const char *format, ...);
void				debug_print_champion(t_champion *champion);
void				debug_print_mem(const void *addr, size_t size);
void				debug_print_map(t_arena *arena);

#pragma mark - Get arguments

void				get_argument_types(uint8_t *mem, t_cursor *cursor);
int					get_direct_argument(char *mem, int t_dir_size, long pos);
int					get_indirect_argument(char *mem, int cursor_pos, int arg_pos, bool idx);

#pragma mark - Utils

// TODO: check if can be removed?
int					ft_strntoi(unsigned char *str, int n);
// TODO: check if can be removed?
uint32_t			rev_bytes_32(uint32_t value);

#pragma mark - Utils 2

bool				is_opcode(t_inst inst);
int					get_timeout(t_inst inst);
long				get_pos(long cursor_pos, long offset);
int					read_4_bytes(uint8_t *mem, long pos);
void				write_4_bytes(uint8_t *mem, long pos, int value);
int					read_2_bytes(uint8_t *mem, long pos);
void				write_2_bytes(uint8_t *mem, long pos, int value);
int					is_registry(int arg);
t_args_type 		get_arg(t_enbyte byte, t_inst inst, int argnr);
int					arg_length(t_args_type type, t_inst inst);
int					args_length(t_enbyte byte, t_inst inst);
t_enbyte 			*get_enbyte(t_arena *arena, long pos);
void				reverse_eb(t_enbyte *eb);

bool 				is_valid_enbyte(t_inst inst, t_enbyte enbyte);

#pragma mark - Operations

typedef void		(*t_op_func)(t_arena *, t_cursor *);

t_op_func 			get_op_func(t_inst inst);
void				inst_live(t_arena *arena, t_cursor *cursor);
void				inst_ld(t_arena *arena, t_cursor *cursor);
void				inst_st(t_arena *arena, t_cursor *cursor);
void				inst_add(t_arena *arena, t_cursor *cursor);
void				inst_sub(t_arena *arena, t_cursor *cursor);
void				inst_and(t_arena *arena, t_cursor *cursor);
void				inst_or(t_arena *arena, t_cursor *cursor);
void				inst_xor(t_arena *arena, t_cursor *cursor);
void				inst_zjmp(t_arena *arena, t_cursor *cursor);
void				inst_ldi(t_arena *arena, t_cursor *cursor);
void				inst_sti(t_arena *arena, t_cursor *cursor);
void				inst_fork(t_arena *arena, t_cursor *cursor);
void				inst_lld(t_arena *arena, t_cursor *cursor);
void				inst_lldi(t_arena *arena, t_cursor *cursor);
void				inst_lfork(t_arena *arena, t_cursor *cursor);
void				inst_aff(t_arena *arena, t_cursor *cursor);

#pragma mark - args loader

bool				preload_args(t_arena *arena_s, t_cursor *cursor);

#pragma mark - Visualizer

void				visual_start(t_arena *arena);
void				visual_update(t_arena *arena, t_cursor *cursor);
void				visual_clear(t_arena *arena_s);
bool				visual_should_update(t_arena *arena);

void				visual_readkey(t_arena *arena);

#endif
