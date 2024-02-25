# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 13:22:51 by idel-poz          #+#    #+#              #
#    Updated: 2024/02/25 14:52:52 by idel-poz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

SRC = ft_printf.c ft_printers.c
OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
MAIN_LIB = libft/libft.a

all: $(NAME)

$(NAME): $(MAIN_LIB) $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(MAIN_LIB): 
	make -C libft/

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C libft/ clean

fclean:	clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean $(NAME)

test: all
	$(CC) $(CFLAGS) main.c ${SRC} libft/libft.a -I./libft && ./a.out && rm -f a.out

.PHONY: all clean fclean re test