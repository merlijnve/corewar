# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: floris <marvin@42.fr>                        +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/11 12:44:37 by floris        #+#    #+#                  #
#    Updated: 2020/08/17 22:50:58 by merlijn       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = corewar
CC = clang
C_FLAGS = -Wall -Wextra -gfull # -Werror - NOTE: Set back after prod.

LIBFT_LOC = ../lib/libft
LIBFT_PRINTF_LOC = ../lib/ft_printf

NAME_LIBFT = $(LIBFT_LOC)/libft.a
NAME_LIBFT_PRINTF = $(LIBFT_PRINTF_LOC)/libftprintf.a

LINK_FLAGS = -lftprintf -lft 

C_HEADERS = \
	vm.h

C_INCLUDES = \
	-I ./ \
	-I ./errors/ \
	-I ../includes/ \
	-I ../lib/ft_printf/

C_SRCS = \
	check_args.c \
	check_champions.c \
	utils.c \
	utils_2.c \
	debug.c \
	arena.c \
	errors/errors.c \
	main.c \
	get_arguments.c \
	ops/add.c \
	ops/sub.c \
	ops/ld.c \
	ops/ldi.c \
	ops/lld.c

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
