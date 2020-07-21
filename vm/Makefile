# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboer <jboer@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2020/07/07 19:33:45 by jboer         #+#    #+#                  #
#    Updated: 2020/07/21 16:33:44 by jboer         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BLACK        := $(shell tput -Txterm setaf 0)
RED          := $(shell tput -Txterm setaf 1)
GREEN        := $(shell tput -Txterm setaf 2)
YELLOW       := $(shell tput -Txterm setaf 3)
LIGHTPURPLE  := $(shell tput -Txterm setaf 4)
PURPLE       := $(shell tput -Txterm setaf 5)
BLUE         := $(shell tput -Txterm setaf 6)
RESET        := $(shell tput -Txterm setaf 7)

NAME = corewar

FILES = main check_args check_champions
SRC = $(FILES:%=src/%.c)
LIB = ../libs/libft/libft.a ../libs/ft_printf/libftprintf.a
INC = ../inc/
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(SRC)
		@echo ">>>>>	${YELLOW}$(NAME) COMPILING STARTED${RESET}	<<<<<"
		@gcc $(FLAGS) $(SRC) $(LIB) -o $(NAME) -I $(INC)
		@echo ">>>>>	${GREEN}$(NAME) COMPILING SUCCESS${RESET}	<<<<<"

clean:
		@echo ">>>>>	${BLUE}CLEANING $(NAME)${RESET}	<<<<<"

fclean: clean
	@echo ">>>>>	${BLUE}REMOVING $(NAME)${RESET}	<<<<<"
	@rm -f $(NAME)

re: fclean all