# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: floris <marvin@42.fr>                        +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/11 12:44:37 by floris        #+#    #+#                  #
#    Updated: 2020/06/11 12:44:39 by floris        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = asm
LIBFT_LOC = ../libft
LIBFT_PRINTF_LOC = ../ft_printf
NAME_LIBFT = $(LIBFT_LOC)/libft.a
NAME_LIBFT_PRINTF = $(LIBFT_PRINTF_LOC)/libftprintf.a

CC = clang
C_FLAGS = -Wall -Wextra # -Werror

AR = ar
AR_FLAGS = rcs

C_HEADERS = \
	$(wildcard *.h)

C_INCLUDES = \
	-I ./

C_SRCS = \
	$(wildcard *.c)

C_OBJS = $(C_SRCS:.c=.o)

all: $(NAME)

%.o: %.c $(C_HEADERS)
	@$(CC) -o $@ -c $< $(C_FLAGS) $(C_INCLUDES) -I $(LIBFT_LOC) -I $(LIBFT_PRINTF_LOC)
	@echo CC: $<

$(NAME): $(C_OBJS) $(NAME_LIBFT) $(NAME_LIBFT_PRINTF)
	@echo CREATING: $(NAME)
	@$(CC) -o $(NAME) $(C_OBJS) -L $(LIBFT_LOC) -L $(LIBFT_PRINTF_LOC) -lft -lftprintf

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

