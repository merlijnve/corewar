/* ************************************************************************** */
/*                                                                            */
/*                                                      ::::::::: :::::::::   */
/*   pf_fsm.h                                          :+:       :+:          */
/*                                                    +:+       +:+           */
/*   By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#       */
/*                                                  +#+       +#+             */
/*   Created: 2019/03/01 17:22:49 by ffredrik      #+#       #+#              */
/*   Updated: 2019/03/30 16:46:10 by ffredrik     ###       ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FSM_H
# define PF_FSM_H

# include "ft_printf_types.h"

# define WIDTH_OPTS "123456789"
# define L_WIDTH_OPTS 9
# define WIDTH_OPTS_X "0123456789"
# define L_WIDTH_OPTS_X 10
# define PRECIS_OPTS_X ".0123456789"
# define L_PRECIS_OPTS_X 11
# define PRECIS_OPTS "."
# define L_PRECIS_OPTS 1
# define WILDCARD_OPTS "*"
# define L_WILDCARD_OPTS 1
# define LENG_OPTS "hlLzjt"
# define L_LENG_OPTS 6
# define FLAG_OPTS "0 #+-'"
# define L_FLAG_OPTS 6
# define CONV_OPTS "cspdiouxXbfFDOU"
# define L_CONV_OPTS 15

typedef t_pf_ret		(*t_state_function)(t_pf_obj *);

t_pf_ret	pf_fsm_controller_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_conv_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_end_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_error_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_flags_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_length_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_precis_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_width_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_start_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_print_object_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_print_empty_object_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_print_char_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_init_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_wildcard_width_state(t_pf_obj *obj);
t_pf_ret	pf_fsm_wildcard_prcs_state(t_pf_obj *obj);

#endif
