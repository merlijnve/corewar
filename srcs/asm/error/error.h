/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: floris <ffredrik@student.codam.nl>           +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/09/13 22:17:00 by floris        #+#    #+#                 */
/*   Updated: 2020/09/13 22:17:00 by floris        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <libft.h>

# include "token_types.h"

# define ERR_PFX_FL "ERROR: %s:"
# define ERR_PFX "ERROR:"

typedef enum e_ret			t_ret;

/*
** Errors
**  0 -  9 Standart errors
** 10 - 29 Input Erros
** 30 - 39 Translation Errors
** 40 - 49 Linking errors
** 50 - 59 Token errors
** 60 - 69 MetaParse errors
** 70 - 79 Validation errors
*/

enum	e_ret
{
	kSuccess = 0,
	kError = -1,
	kErrorAlloc = -2,
	kErrorOpeningFile = -3,
	kErrorEmptyFile = -4,

	kErrorInput = -10,
	kErrorParse = -11,
	kErrorGarbageFound = -12,

	kErrorTranslation = -30,
	kErrorInvalidArgumentCount = -31,
	kErrorUndefineInstructionError = -32,

	kErrorLinking = -40,
	kErrorLinkNotFound = -41,

	kErrorToken = -50,

	kErrotMetaParse = -60,
	kErrorNameTooLong = -61,
	kErrorCommentTooLong = -62,

	kErrorValidation = -70,
	kErrorBadCharInLabel = -71,
};

typedef struct s_error		t_error;

struct	s_error
{
	t_ret		code;
	t_tksave	*token;
	t_tksave	rtoken;
	const char	*file_name;
};

typedef struct s_errinfo	t_errinfo;

struct	s_errinfo
{
	const char	*format;
};

void	print_error(t_error *err, t_list *lines);
t_ret	set_error(const char *file, t_index idx, t_ret ret, t_error *error);
t_ret	set_err_loc(t_place loc, t_ret ret, t_error *error);
t_ret	set_err_token(t_tksave *token, t_ret ret, t_error *error);

#endif
