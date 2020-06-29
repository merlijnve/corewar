# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/29 14:58:00 by mvan-eng      #+#    #+#                  #
#    Updated: 2020/06/29 17:34:08 by mvan-eng      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = asm

ASMF = main
ASMSRC = $(ASMF:%=src/%.c)
LIB = ../libs/libft/libft.a

all: $(NAME)

$(NAME):
		@echo ">>>>>	$(NAME) COMPILING STARTED	<<<<<"
		@echo ">>>>>	$(NAME) COMPILING SUCCESS	<<<<<"

clean:
		@echo ">>>>>	CLEANING $(NAME)	<<<<<"

fclean: clean
	@echo ">>>>>	REMOVING $(NAME)	<<<<<"
	@rm -f $(NAME)

re: fclean all
