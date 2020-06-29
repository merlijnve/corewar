# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/29 15:11:36 by mvan-eng      #+#    #+#                  #
#    Updated: 2020/06/29 17:34:14 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = corewar

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
		@echo ">>>>>	$(NAME) COMPILING STARTED	<<<<<"
		@make -C libs/libft
		@make -C libs/ft_printf
		#@make -C asm
		#@make -C [name of vm folder]
		@echo ">>>>>	$(NAME) COMPILING SUCCESS	<<<<<"

clean:
		@echo ">>>>>	CLEANING $(NAME)	<<<<<"
		@make -C libs/libft clean
		@make -C libs/ft_printf clean
		#@make -C asm clean
		#@make -C [name of vm folder] clean
		
fclean:
		@echo ">>>>>	REMOVING $(NAME)	<<<<<"
		@make -C libs/libft fclean
		@make -C libs/ft_printf fclean
		#@make -C asm fclean
		#@make -C [name of vm folder] fclean

re: fclean all