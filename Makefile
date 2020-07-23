# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/29 15:11:36 by mvan-eng      #+#    #+#                  #
#    Updated: 2020/07/07 18:28:33 by jboer         ########   odam.nl          #
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

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@echo ">>>>>	${YELLOW}$(NAME) COMPILING STARTED${RESET}	<<<<<"
		@make -C libs/libft
		@make -C libs/ft_printf
		# @make -C asm
		@make -C vm
		@echo ">>>>>	${GREEN}$(NAME) COMPILING SUCCESS${RESET}	<<<<<"

clean:
		@echo ">>>>>	${BLUE}CLEANING $(NAME)${RESET}	<<<<<"
		@make -C libs/libft clean
		@make -C libs/ft_printf clean
		# @make -C asm clean
		# @make -C [name of vm folder] clean
		
fclean:
		@echo ">>>>>	${BLUE}REMOVING $(NAME)${RESET}	<<<<<"
		@make -C libs/libft fclean
		@make -C libs/ft_printf fclean
		# @make -C asm fclean
		# @make -C [name of vm folder] fclean

re: fclean all