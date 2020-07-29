/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   ft_printf_types.h                                 :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:45 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:02 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_TYPES_H
# define FT_PRINTF_TYPES_H

# include <stddef.h>
# include <stdarg.h>
# include <strings.h>
# include <stdio.h>

/*
** t_ft_return contains return codes
*/

enum	e_pf_ret
{
	PF_RET_SUCCESS = 0,
	PF_RET_HAS_MORE = 1,
	PF_RET_ERROR = -1,
	PF_RET_FORMAT_ERROR = -2,
	PF_RET_WRITE_ERROR = -3,
	PF_RET_NO_STATE_SET = -10,

	PF_RET_CONV_STATE = 10,
	PF_RET_END_STATE = 11,
	PF_RET_ERROR_STATE = 12,
	PF_RET_FLAGS_STATE = 13,
	PF_RET_LENGTH_STATE = 14,
	PF_RET_PRECIS_STATE = 15,
	PF_RET_WIDTH_STATE = 16,
	PF_RET_START_STATE = 17,
	PF_RET_PRINT_OBJECT_STATE = 18,
	PF_RET_PRINT_EMPTY_OBJECT_STATE = 19,
	PF_RET_PRINT_CHAR_STATE = 20,
	PF_RET_INIT_STATE = 21,
	PF_RET_WILDCARD_PRCS_STATE = 22,
	PF_RET_WILDCARD_WIDTH_STATE = 23,
};

typedef enum e_pf_ret		t_pf_ret;

/*
** t_pf_conversion contains the conversion types
*/

enum	e_pf_conv
{
	NOT_A_CONV = (unsigned long long)1 << 0,
	CONV_NS = (unsigned long long)1 << 1,

	XA_CONV = (unsigned long long)1 << 2,
	XB_CONV = (unsigned long long)1 << 3,
	XC_CONV = (unsigned long long)1 << 4,
	XD_CONV = (unsigned long long)1 << 5,
	XE_CONV = (unsigned long long)1 << 6,
	XF_CONV = (unsigned long long)1 << 7,
	XG_CONV = (unsigned long long)1 << 8,
	XH_CONV = (unsigned long long)1 << 9,
	XI_CONV = (unsigned long long)1 << 10,
	XJ_CONV = (unsigned long long)1 << 11,
	XK_CONV = (unsigned long long)1 << 12,
	XL_CONV = (unsigned long long)1 << 13,
	XM_CONV = (unsigned long long)1 << 14,
	XN_CONV = (unsigned long long)1 << 15,
	XO_CONV = (unsigned long long)1 << 16,
	XP_CONV = (unsigned long long)1 << 17,
	XQ_CONV = (unsigned long long)1 << 18,
	XR_CONV = (unsigned long long)1 << 19,
	XS_CONV = (unsigned long long)1 << 20,
	XT_CONV = (unsigned long long)1 << 21,
	XU_CONV = (unsigned long long)1 << 22,
	XV_CONV = (unsigned long long)1 << 23,
	XW_CONV = (unsigned long long)1 << 24,
	XX_CONV = (unsigned long long)1 << 25,
	XY_CONV = (unsigned long long)1 << 26,
	XZ_CONV = (unsigned long long)1 << 27,

	A_CONV = (unsigned long long)1 << 34,
	B_CONV = (unsigned long long)1 << 35,
	C_CONV = (unsigned long long)1 << 36,
	D_CONV = (unsigned long long)1 << 37,
	E_CONV = (unsigned long long)1 << 38,
	F_CONV = (unsigned long long)1 << 39,
	G_CONV = (unsigned long long)1 << 40,
	H_CONV = (unsigned long long)1 << 41,
	I_CONV = (unsigned long long)1 << 42,
	J_CONV = (unsigned long long)1 << 43,
	K_CONV = (unsigned long long)1 << 44,
	L_CONV = (unsigned long long)1 << 45,
	M_CONV = (unsigned long long)1 << 46,
	N_CONV = (unsigned long long)1 << 47,
	O_CONV = (unsigned long long)1 << 48,
	P_CONV = (unsigned long long)1 << 49,
	Q_CONV = (unsigned long long)1 << 50,
	R_CONV = (unsigned long long)1 << 51,
	S_CONV = (unsigned long long)1 << 52,
	T_CONV = (unsigned long long)1 << 53,
	U_CONV = (unsigned long long)1 << 54,
	V_CONV = (unsigned long long)1 << 55,
	W_CONV = (unsigned long long)1 << 56,
	X_CONV = (unsigned long long)1 << 57,
	Y_CONV = (unsigned long long)1 << 58,
	Z_CONV = (unsigned long long)1 << 59,
};

typedef enum e_pf_conv		t_pf_conv;

/*
** t_pf_LEN_MOD contains the len_modifier types
*/

typedef enum e_pf_len_mod	t_pf_len_mod;

enum	e_pf_len_mod
{
	HH_PF_LEN_MOD = 1 << 16,
	H_PF_LEN_MOD = 1 << 15,
	L_PF_LEN_MOD = 1 << 14,
	LL_PF_LEN_MOD = 1 << 13,
	XL_PF_LEN_MOD = 1 << 12,
	J_PF_LEN_MOD = 1 << 11,
	T_PF_LEN_MOD = 1 << 10,
	Z_PF_LEN_MOD = 1 << 9,
	V_PF_LEN_MOD = 1 << 8,
	VH_PF_LEN_MOD = 1 << 7,
	VL_PF_LEN_MOD = 1 << 6,
	VLL_PF_LEN_MOD = 1 << 5,
	LEN_MOD_NS = 1 << 1,
	NO_LEN_MOD = 1 << 0,
};

/*
** t_pf_flag contains the flag types
*/

typedef enum e_pf_flag	t_pf_flag;

enum	e_pf_flag
{
	PF_HT_FLAG = 1 << 7,
	PF_ZR_FLAG = 1 << 6,
	PF_SP_FLAG = 1 << 5,
	PF_PL_FLAG = 1 << 4,
	PF_MN_FLAG = 1 << 3,
	PF_AP_FLAG = 1 << 2,
};

typedef union u_pf_value	t_pf_value;

union	u_pf_value
{
	signed int			s_it_value;
	signed char			s_ch_value;
	signed short		s_sh_value;
	signed long			s_ln_value;
	signed long long	s_ll_value;
	unsigned int		u_it_value;
	unsigned char		u_ch_value;
	unsigned short		u_sh_value;
	unsigned long		u_ln_value;
	unsigned long long	u_ll_value;
	float				s_fl_value;
	double				s_db_value;
	long double			s_ld_value;
	char				*s_ch_ptr_value;
	void				*ptr;
};

# define WIDTH_NS -1
# define PRCS_NS -1
# define LEN_NS -1

typedef enum e_pf_dest_type	t_pf_dest_type;

enum	e_pf_dest_type
{
	PRINT_DEST_STREAM,
	PRINT_DEST_FIDES,
};

typedef union u_pf_dest		t_pf_dest;

union	u_pf_dest
{
	FILE	*file;
	int		fd;
};

typedef struct s_pf_part	t_pf_part;

struct	s_pf_part
{
	t_pf_flag				flags;
	int						width;
	int						prcs;
	t_pf_len_mod			len_mod;
	t_pf_conv				conv;
	t_pf_value				value;
};

typedef struct s_pf_obj		t_pf_obj;

struct	s_pf_obj
{
	const char		*input;
	size_t			chr_wrtn;
	t_pf_part		*part;
	va_list			*args;
	t_pf_dest_type	dtype;
	t_pf_dest		dest;
	t_pf_ret		(*print)(const char *, ssize_t, t_pf_obj *);
};

typedef struct s_lenblock	t_lenblock;

struct	s_lenblock
{
	int				r_prsc;
	int				r_width;
	int				pad_len;
	int				total_len;
	char			*order;
};

typedef	struct s_ld_parts	t_ld_parts;

struct	s_ld_parts
{
	unsigned long	m;
	unsigned long	s_exp;
};

typedef union u_pf_f2u		t_pf_f2u;

union	u_pf_f2u
{
	long double		f;
	t_ld_parts		ld;
};

# define LOCAL_BUFFER_SIZE 2048

typedef	struct s_pf_buffer	t_pf_buffer;

struct	s_pf_buffer
{
	const char	*data[LOCAL_BUFFER_SIZE + 1];
	size_t		idx;
};

# define LD_SIGN 0x0000000000008000
# define LD_EXP 0x0000000000007FFF
# define LD_FRACTION 0x7FFFFFFFFFFFFFFF
# define LD_MANTISSA_BITS 64UL
# define LD_EXP_BIAS 16383
# define LD_PRCS 23

#endif
