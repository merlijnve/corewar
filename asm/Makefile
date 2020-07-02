# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/29 14:58:00 by mvan-eng      #+#    #+#                  #
#    Updated: 2020/07/02 12:01:37 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = asm

FILES = main
SRC = $(FILES:%=src/%.c)
LIB = ../libs/libft/libft.a ../libs/ft_printf/libftprintf.a
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC)
		@echo ">>>>>	$(NAME) COMPILING STARTED	<<<<<"
		@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME)
		@echo ">>>>>	$(NAME) COMPILING SUCCESS	<<<<<"

clean:
		@echo ">>>>>	CLEANING $(NAME)	<<<<<"

fclean: clean
	@echo ">>>>>	REMOVING $(NAME)	<<<<<"
	@rm -f $(NAME)

re: fclean all
