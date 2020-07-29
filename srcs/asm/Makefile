# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: floris <marvin@42.fr>                        +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/11 12:44:37 by floris        #+#    #+#                  #
#    Updated: 2020/07/14 16:29:56 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = asm
CC = clang
C_FLAGS = -Wall -Wextra # -Werror - NOTE: Set back after prod.

LIBFT_LOC = ../lib/libft
LIBFT_PRINTF_LOC = ../lib/ft_printf

NAME_LIBFT = $(LIBFT_LOC)/libft.a
NAME_LIBFT_PRINTF = $(LIBFT_PRINTF_LOC)/libftprintf.a

LINK_FLAGS = -lftprintf -lft

C_HEADERS = asm.h
C_INCLUDES = -I ../includes/
C_SRCS = main.c check_args.c
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
