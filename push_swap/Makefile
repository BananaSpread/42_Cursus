# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 12:58:36 by idel-poz          #+#    #+#              #
#    Updated: 2024/09/21 13:01:33 by idel-poz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c
OBJ = $(SRC:.c=.o)

NAME = push_swap
LIBFT_PATH = Libft/
LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	cp $(LIBFT) $(NAME)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) -I./$(LIBFT_PATH)

$(LIBFT):
	make -sC $(LIBFT_PATH)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	make -sC $(LIBFT_PATH) clean

fclean: clean
	make -sC $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re