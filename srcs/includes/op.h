/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   op.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: zaz <marvin@42.fr>                           +#+                     */
/*                                                   +#+                      */
/*   Created: 2013/10/04 11:33:27 by zaz           #+#    #+#                 */
/*   Updated: 2020/07/31 17:36:09 by wmisiedj      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

#define IND_SIZE				2
#define REG_SIZE				4
#define DIR_SIZE				REG_SIZE

#define REG_SIZE_ASM			1
#define IND_SIZE_ASM			2

# define REG_CODE				1
# define DIR_CODE				2
# define IND_CODE				3


#define MAX_ARGS_NUMBER			4
#define MAX_PLAYERS				4
#define MEM_SIZE				(4*1024)
#define IDX_MOD					(MEM_SIZE / 8)
#define CHAMP_MAX_SIZE			(MEM_SIZE / 6)

#define COMMENT_CHAR			'#'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'
#define SEPARATOR_CHAR			','
#define REGISTER_CHAR			'r'


#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"

#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"

#define REG_NUMBER				16

#define CYCLE_TO_DIE			1536
#define CYCLE_DELTA				50
#define NBR_LIVE				21
#define MAX_CHECKS				10

/*
**
*/

// TODO: remove this

#define T_REG					1
#define T_DIR					2
#define T_IND					4
#define T_LAB					8

/*
**
*/

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0x00ea83f3
# define COREWAR_EXEC_MAGICR	0xf383ea00

#include <stdbool.h>

typedef struct		header_s
{
  unsigned int		magic;
  char				prog_name[PROG_NAME_LENGTH + 1];
  unsigned int		prog_size;
  char				comment[COMMENT_LENGTH + 1];
}					header_t;

#pragma mark - from asm

typedef enum e_inst			t_inst;
typedef enum e_args_type	t_args_type;

enum e_inst
{
	kInstNone = -1,
	kInstUndef = 0x00,
	kInstLive = 0x01,
	kInstLd = 0x02,
	kInstSt = 0x03,
	kInstAdd = 0x04,
	kInstSub = 0x05,
	kInstAnd = 0x06,
	kInstOr = 0x07,
	kInstXor = 0x08,
	kInstZjmp = 0x09,
	kInstLdi = 0x0A,
	kInstSti = 0x0B,
	kInstFork = 0x0C,
	kInstLld = 0x0D,
	kInstLldi = 0x0E,
	kInstLfork = 0x0F,
	kInstAff = 0x10,
};

enum e_args_type
{
	kTReg = 0b01,
	kTDir = 0b10,
	kTInd = 0b11,
	kTNone = 0b00,
};

typedef struct s_enbyte		t_enbyte;

struct	s_enbyte
{
	t_args_type	arg1 : 2;
	t_args_type	arg2 : 2;
	t_args_type	arg3 : 2;
	t_args_type	arg4 : 2;
};

/*
** Info struct for operations
*/

typedef struct s_opinfo t_opinfo;

struct s_opinfo
{
	int			argc;
	int			dir_size;
	int			timeout;
	bool		has_enbyte;
	t_enbyte	v_args[3]; // valid args
};


#pragma mark - Shared

const t_opinfo *get_opinfo(t_inst intst);
