# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: floris <marvin@42.fr>                        +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/11 12:44:37 by floris        #+#    #+#                  #
#    Updated: 2020/09/15 13:42:35 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = clang
C_FLAGS = -Wall -Wextra -gfull # -Werror - NOTE: Set back after prod.

LIBFT_LOC = ../lib/libft
LIBFT_PRINTF_LOC = ../lib/ft_printf

NAME_LIBFT = $(LIBFT_LOC)/libft.a
NAME_LIBFT_PRINTF = $(LIBFT_PRINTF_LOC)/libftprintf.a

LINK_FLAGS = -lftprintf -lft -lncurses

C_HEADERS = \
	./errors/vm_errors.h \
	./vm.h

C_INCLUDES = \
	-I ./ \
	-I ./errors/ \
	-I ../includes/ \

C_SRCS = \
	../lib/shared/shared.c \
	./cycle.c \
	./vm.c \
	./champions.c \
	./args_loader.c \
	./check_args.c \
	./check_champions.c \
	./cursors.c \
	./debug.c \
	./errors/vm_errors.c \
	./get_arguments.c \
	./cursor_util.c \
	./main.c \
	./op_arg_checker.c \
	./ops/add.c \
	./ops/aff.c \
	./ops/and.c \
	./ops/fork.c \
	./ops/ld.c \
	./ops/ldi.c \
	./ops/lfork.c \
	./ops/live.c \
	./ops/lld.c \
	./ops/lldi.c \
	./ops/ops.c \
	./ops/or.c \
	./ops/st.c \
	./ops/sti.c \
	./ops/sub.c \
	./ops/xor.c \
	./ops/zjmp.c \
	./bytes.c \
	./enbytes.c \
	./args.c \
	./visual/visual_main.c \
	./visual/keystrokes.c \
	./visual/visual_utils.c \
	./dump.c \
	./unsorted_utils.c \
	./debug_utils.c


C_OBJS = $(C_SRCS:%.c=%.o)

.PHONY: fclean clean all re

%.o: %.c $(C_HEADERS)
	@$(CC) -o $@ -c $< $(C_FLAGS) $(C_INCLUDES)
	@echo CC: $<

all: $(NAME)

$(NAME): $(C_OBJS) $(NAME_LIBFT) $(NAME_LIBFT_PRINTF)
	@echo CREATING: $(NAME)
	@$(CC) -o $(NAME) $(C_OBJS) $(C_INCLUDES) -L $(LIBFT_LOC) -L $(LIBFT_PRINTF_LOC) $(LINK_FLAGS)

$(NAME_LIBFT):
	@make -C $(LIBFT_LOC)

$(NAME_LIBFT_PRINTF):
	@make -C $(LIBFT_PRINTF_LOC)

fclean: clean
	@make -C $(LIBFT_LOC) fclean
	@make -C $(LIBFT_PRINTF_LOC) fclean
	@echo DELETING: $(NAME)
	@rm -f $(NAME)

clean:
	@make -C $(LIBFT_LOC) clean
	@make -C $(LIBFT_PRINTF_LOC) clean
	@echo DELETING: $(C_OBJS)
	@rm -f $(C_OBJS)

re: fclean $(NAME)
