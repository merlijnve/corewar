# **************************************************************************** #
#                                                                              #
#                                                       ::::::::: :::::::::    #
#    Makefile                                          :+:       :+:           #
#                                                     +:+       +:+            #
#    By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#        #
#                                                   +#+       +#+              #
#    Created: 2019/01/08 16:32:51 by ffredrik      #+#       #+#               #
#    Updated: 2019/12/12 21:34:49 by ffredrik     ###       ###                #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_LOC = ../libft/
NAME_DL = libftprintf.dylib
NAME_LIBFT = $(LIBFT_LOC)/libft.a

CC = clang
C_FLAGS = -Wall -Wextra

AR = ar
AR_FLAGS = rcs

C_HEADERS = \
	./FSM/pf_fsm.h \
	./ft_print_functions.h \
	./ft_printf.h \
	./ft_printf_types.h \
	./object_printing/extra/pf_print_nchar.h \
	./object_printing/extra/print_num_full/pf_print_num_full.h \
	./object_printing/ft_printf_print.h \
	./object_printing/print_conv_str/float_aux/float_aux.h \
	./object_printing/print_conv_str/pf_print_conv.h \
	./part_completion/pf_choose_length_for_mod.h \
	./utils.h

C_INCLUDES = \
	-I ./ \
	-I ./libft/ \
	-I ./FSM/ \
	-I ./object_printing/ \
	-I ./object_printing/extra/ \
	-I ./object_printing/extra/print_num_full/ \
	-I ./object_printing/print_conv_str \
	-I ./object_printing/print_conv_str/float_aux \
	-I ./part_completion/ \
	-I ./object_printing/float_aux

C_SRCS = \
	./FSM/pf_fsm_controller_state.c \
	./FSM/pf_fsm_conv_state.c \
	./FSM/pf_fsm_end_state.c \
	./FSM/pf_fsm_error_state.c \
	./FSM/pf_fsm_flags_state.c \
	./FSM/pf_fsm_init_state.c \
	./FSM/pf_fsm_lenght_state.c \
	./FSM/pf_fsm_precis_state.c \
	./FSM/pf_fsm_print_char_state.c \
	./FSM/pf_fsm_print_empty_object_state.c \
	./FSM/pf_fsm_print_object_state.c \
	./FSM/pf_fsm_start_state.c \
	./FSM/pf_fsm_width_state.c \
	./FSM/pf_fsm_wildcard_prcs_state.c \
	./FSM/pf_fsm_wildcard_width_state.c \
	./ft_print_functions.c \
	./ft_printf.c \
	./ft_vprintf.c \
	./object_printing/extra/pf_print_nchar.c \
	./object_printing/extra/print_num_full/pf_print_num_full_d.c \
	./object_printing/ft_printf_print_object.c \
	./object_printing/ft_printf_print_part_b.c \
	./object_printing/ft_printf_print_part_c.c \
	./object_printing/ft_printf_print_part_d.c \
	./object_printing/ft_printf_print_part_f.c \
	./object_printing/ft_printf_print_part_i.c \
	./object_printing/ft_printf_print_part_o.c \
	./object_printing/ft_printf_print_part_p.c \
	./object_printing/ft_printf_print_part_s.c \
	./object_printing/ft_printf_print_part_u.c \
	./object_printing/ft_printf_print_part_x.c \
	./object_printing/print_conv_str/float_aux/float_aux.c \
	./object_printing/print_conv_str/float_aux/float_lhs.c \
	./object_printing/print_conv_str/float_aux/float_rhs.c \
	./object_printing/print_conv_str/float_aux/ft_ftoa.c \
	./object_printing/print_conv_str/pf_print_conv_c.c \
	./object_printing/print_conv_str/pf_print_conv_d.c \
	./object_printing/print_conv_str/pf_print_conv_f.c \
	./object_printing/print_conv_str/pf_print_conv_o.c \
	./object_printing/print_conv_str/pf_print_conv_p.c \
	./object_printing/print_conv_str/pf_print_conv_s.c \
	./object_printing/print_conv_str/pf_print_conv_u.c \
	./object_printing/print_conv_str/pf_print_conv_x.c \
	./part_completion/pf_choose_length_for_mod.c \
	./utils.c

C_OBJS = $(C_SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(C_HEADERS)
	@$(CC) -o $@ -c $< $(C_FLAGS) $(C_INCLUDES) -I ../libft/
	@echo CC: $<

$(NAME): $(C_OBJS)
	@echo CREATING: $(NAME)
	@$(AR) $(AR_FLAGS) $(NAME) $(C_OBJS)

$(NAME_LIBFT):
	@make -C $(LIBFT_LOC)

$(NAME_DL): $(C_OBJS) $(NAME_LIBFT)
	@echo CREATING: $(NAME_DL)
	@clang -fPIC -dynamiclib -o $(NAME_DL) $(C_OBJS) -lft -L../libft/

dylib: $(NAME_DL)

fclean: clean
	@make -C $(LIBFT_LOC) fclean
	@echo DELETING: $(NAME)
	@rm -f $(NAME)
	@echo DELETING: $(NAME_DL)
	@rm -f $(NAME_DL)

clean:
	@make -C $(LIBFT_LOC) clean
	@rm -f $(C_OBJS)

re: fclean $(NAME)
