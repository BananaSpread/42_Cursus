# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/21 12:58:36 by idel-poz          #+#    #+#              #
#    Updated: 2024/09/29 18:10:55 by idel-poz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

MOVEMENTS_PATH = movements/
MOEVEMENTS_SRC = $(MOVEMENTS_PATH)ra.c $(MOVEMENTS_PATH)rb.c $(MOVEMENTS_PATH)rr.c \
	$(MOVEMENTS_PATH)rra.c $(MOVEMENTS_PATH)rrb.c $(MOVEMENTS_PATH)rrr.c \
	$(MOVEMENTS_PATH)sa.c $(MOVEMENTS_PATH)sb.c $(MOVEMENTS_PATH)ss.c \
	$(MOVEMENTS_PATH)pa.c $(MOVEMENTS_PATH)pb.c

SRC = push_swap.c sorter.c parser.c stack_utils.c cleaner.c \
	rotate.c rotate_utils.c find_utils.c \
	solver_1.c solver_2.c \
	$(MOEVEMENTS_SRC)
	
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
	valgrind -s ./push_swap 123 0 "4" "-3" "+5" " +12" 2147483647 122

test2: all
	valgrind -s ./push_swap "0 1 2 3 4 5 6 7 8 9"

test3: all
	valgrind -s ./push_swap 2 1 3 6 5 8 -2147483649