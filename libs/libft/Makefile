# **************************************************************************** #
#                                                                              #
#                                                       ::::::::: :::::::::    #
#    Makefile                                          :+:       :+:           #
#                                                     +:+       +:+            #
#    By: ffredrik <ffredrik@student.codam.nl>        :#::+::#  :#::+::#        #
#                                                   +#+       +#+              #
#    Created: 2019/01/08 16:32:51 by ffredrik      #+#       #+#               #
#    Updated: 2019/02/11 20:48:31 by ffredrik     ###       ###                #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -g

AR = ar
ARFLAGS = rcs

HEADERS = ./libft.h

SRCS =	ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islower.c \
		ft_isprint.c \
		ft_isspace.c \
		ft_isupper.c \
		ft_strisdigit.c \
		ft_itoa.c \
		ft_itoa_base.c \
		ft_log.c \
		ft_memalloc.c \
		ft_memccmp.c \
		ft_memccpy.c \
		ft_memrcpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memdup.c \
		ft_memichr.c \
		ft_memmove.c \
		ft_memrchr.c \
		ft_memset.c \
		ft_putnbr_fd.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strclen.c \
		ft_strllen.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_strichr.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strndup.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_strctrim.c \
		ft_strcnt.c \
		ft_strncnt.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_min.c \
		ft_max.c \
		ft_strlower.c \
		ft_strupper.c \
		ft_utoa_base.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstrev.c \
		ft_dictnew.c \
		ft_dictadd.c \
		ft_dictget.c \
		ft_dictremove.c \
		ft_dictfree.c \
		ft_hdictnew.c \
		ft_hdictadd.c \
		ft_hdictget.c \
		ft_hdictremove.c \
		ft_hdictfree.c \
		ft_hdicthash.c \
		get_next_line.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(HEADERS)
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo CC: $<

$(NAME): $(OBJS)
	@echo MAKING LIBRARY
	@$(AR) $(ARFLAGS) $(NAME) $(OBJS)

fclean: clean
	@echo REMOVING LIBRARY
	@rm -f $(NAME)

clean:
	@echo REMOVING OBJECT FILES
	@rm -f $(OBJS)

re: fclean $(NAME)
