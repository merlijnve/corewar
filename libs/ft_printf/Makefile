# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboer <jboer@student.codam.nl>               +#+                      #
#                                                    +#+                       #
#    Created: 2019/08/19 16:21:30 by jboer         #+#    #+#                  #
#    Updated: 2020/07/07 18:28:34 by jboer         ########   odam.nl          #
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

NAME = libftprintf.a

FLAGS = -Wall -Werror -Wextra

CC = gcc

FILES = ft_printf fmtflow print_string fill_struct get_va_chr add_flags \
fill_struct get_va_base get_va_int get_va_ptr get_va_str get_va_uns \
make_width_base print_perc get_va_flt get_va_binary get_va_array

LIBFT = ft_atoi ft_lltoa ft_memalloc ft_memdel ft_memset ft_nbrbase ft_putchar\
ft_putstr ft_str_to_uppercase ft_strchr ft_strcpy ft_strdel ft_strdup \
ft_strjoin ft_strlen ft_strncpy ft_strnew ft_ulltoa ft_isdigit ft_llintlen \
ft_longtos ft_ullintlen ft_fltoa ft_putnbr ft_putnbrlong ft_putendl ft_fltoa \
ft_straddtofront ft_straddtoend ft_strcmp ft_unbrbase ft_digitc

SRCS = $(FILES:%=srcs/%.c)

SRCSL = $(LIBFT:%=../libft/srcs/%.c)

OBJ = $(FILES:%=%.o)

OBJL = $(LIBFT:%=%.o)

LIB = libft/libft.a

all: $(NAME)

$(NAME):
	@echo ">>>>>	${YELLOW}$(NAME) COMPILING STARTED${RESET}	<<<<<"
	@gcc -c $(FLAGS) $(SRCS) $(SRCSL) -I $(LIB)
	@ar rc $(NAME) $(OBJ) $(OBJL)
	@ranlib $(NAME)
	@echo ">>>>>	${GREEN}$(NAME) COMPILING SUCCESS${RESET}	<<<<<"

clean:
	@echo ">>>>>	${BLUE}CLEANING $(NAME)${RESET}	<<<<<"
	@rm -rf $(OBJ) $(OBJL)

fclean: clean
	@echo ">>>>>	${BLUE}REMOVING $(NAME)${RESET}	<<<<<"
	@rm -f $(NAME)

re: fclean all
