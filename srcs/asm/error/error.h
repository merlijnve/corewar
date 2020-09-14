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
#define ERROR_H

#include <libft.h>

#include "token_types.h"

#define ERR_PFX_FL "ERROR: %s:"
#define ERR_PFX "ERROR:"

typedef enum e_ret			t_ret;

// Errors
//  0 -  9 Standart errors
// 10 - 29 Input Erros
// 30 - 39 Translation Errors
// 40 - 49 Linking errors
// 50 - 69 Token errors
//

enum	e_ret
{
	kSuccess = 0,
	kError = -1,
	kErrorAlloc = -2,
	kErrorOpeningFile = -3,

	kInputError = -10,
	kParseError = -11,

	kTranslationError = -30,
	kInvalidArgumentCount = -31,

	kLinkingError = -40,
	kLinkNotFoundError = -41,

	kTokenError = -50,

	kMetaParseError = -60,
	kMPNameTooLong = -61,
	kMPCommentTooLong = -62,
};

typedef struct s_error		t_error;

struct s_error
{
	t_ret		code;
	t_tksave	*token;
	t_tksave	rtoken;
};

typedef struct s_errinfo	t_errinfo;

struct		s_errinfo
{
	const char	*format;
};

void	print_error(t_error *error);

#endif
