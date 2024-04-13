# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 13:22:51 by idel-poz          #+#    #+#              #
#    Updated: 2024/04/13 17:03:10 by idel-poz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

SRC = ft_printf.c ft_printers.c
OBJ = $(SRC:.c=.o)

NAME = libftprintf.a
MAIN_LIB_PATH = libft/
MAIN_LIB = $(MAIN_LIB_PATH)libft.a

all: $(NAME)

$(NAME): $(MAIN_LIB) $(OBJ)
	cp $(MAIN_LIB) $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

$(MAIN_LIB): 
	make -C $(MAIN_LIB_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -C $(MAIN_LIB_PATH) clean

fclean:	clean
	rm -f $(NAME)
	make -C $(MAIN_LIB_PATH) fclean

re: fclean $(NAME)

test: all
	$(CC) $(CFLAGS) main.c ${NAME} -L. && ./a.out && rm -f a.out

.PHONY: all clean fclean re test
