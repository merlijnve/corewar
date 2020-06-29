# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mvan-eng <mvan-eng@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/01/10 14:10:44 by mvan-eng      #+#    #+#                  #
#    Updated: 2020/04/14 16:01:06 by merlijn       ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAGS = -Wall -Wextra -Werror
FILES = ft_isdigit.c ft_memcmp.c ft_putendl_fd.c ft_strcmp.c ft_striter.c \
ft_strncmp.c ft_strsub.c ft_islower.c ft_memcpy.c ft_putnbr.c ft_strcpy.c \
ft_striteri.c ft_strncpy.c ft_strtrim.c ft_atoi.c ft_isprint.c ft_memdel.c \
ft_putnbr_fd.c ft_strdcount.c ft_strjoin.c ft_strnequ.c ft_tolower.c \
ft_bzero.c ft_isupper.c ft_memmove.c ft_putstr.c ft_strdcpy.c ft_strlcat.c\
ft_strnew.c ft_toupper.c ft_digitc.c ft_itoa.c ft_memset.c ft_putstr_fd.c \
ft_strdel.c ft_strlen.c ft_strnstr.c ft_isalnum.c ft_memalloc.c ft_putchar.c\
ft_strcat.c ft_strdlen.c ft_strmap.c ft_strrchr.c ft_isalpha.c ft_memccpy.c \
ft_putchar_fd.c ft_strchr.c ft_strdup.c ft_strmapi.c ft_strsplit.c \
ft_isascii.c ft_memchr.c ft_putendl.c ft_strclr.c ft_strequ.c ft_strncat.c \
ft_strstr.c ft_lstnew.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c \
ft_lstmap.c ft_lncount.c ft_strndup.c ft_putcmap.c get_next_line.c ft_mapdel.c\
ft_putimap.c ft_count_pointers.c ft_longlongc.c ft_lltoa.c ft_datoi.c \
ft_nbrbase.c ft_natoi.c ft_putnbrlong.c ft_intlen.c ft_intos.c ft_longtos.c \
ft_llintlen.c ft_str_to_uppercase.c ft_charindex.c ft_ulltoa.c ft_ullintlen.c \
ft_fltoa.c ft_straddtofront.c ft_straddtoend.c ft_unbrbase.c ft_arrdel.c \
ft_strlchr.c

SRC = $(FILES:%=srcs/%)

OBJ = $(FILES:.c=.o)

all: $(NAME)

$(NAME):
	@echo ">>>>>	$(NAME) COMPILING STARTED	<<<<<"
	@gcc $(FLAGS) -c $(SRC)
	@ar rcs libft.a $(OBJ)
	@ranlib $(NAME)
	@rm -f $(OBJ)
	@echo ">>>>>	$(NAME) COMPILING SUCCESS	<<<<<"

clean:
	@echo ">>>>>	CLEANING $(NAME)	<<<<<"
	@rm -f $(OBJ)

fclean: clean
	@echo ">>>>>	REMOVING $(NAME)	<<<<<"
	@rm -f $(NAME)

re: fclean all
