# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 12:58:36 by idel-poz          #+#    #+#              #
#    Updated: 2024/09/22 18:26:09 by idel-poz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = push_swap.c stack_utils.c error_utils.c
OBJ = $(SRC:.c=.o)

NAME = push_swap
LIBFT_PATH = Libft/
LIBFT = $(LIBFT_PATH)libft.a

all: $(NAME)
	@echo "push_swap compiled successfully."

$(NAME): $(LIBFT) $(OBJ)
	@cp $(LIBFT) $(NAME)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIBFT) -I./$(LIBFT_PATH)

$(LIBFT):
	@make -sC $(LIBFT_PATH)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@make -sC $(LIBFT_PATH) clean

fclean: clean
	@make -sC $(LIBFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# TESTS #
test1: all
	valgrind -s ./push_swap 123 0 "4" "-3" "+5" " +12" 2147483647 121

test2: all
	valgrind -s ./push_swap "0 1 2 3 4 5 6 7 8 9"