# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 12:42:32 by idel-poz          #+#    #+#              #
#    Updated: 2024/09/07 21:02:18 by idel-poz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c
OBJ = $(SRC:.c=.o)

NAME = pipex
LIBFT_PATH = libft/
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
	rm -f result*.txt

fclean: clean
	make -sC $(LIBFT_PATH) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# TESTS
TEST_FILE_IN = pipex.c

CAT_CMD = cat
TEST_0_CMD = "grep include"
TEST_1_CMD = "grep if"
TEST_2_CMD = "wc -l"
TEST_3_CMD = "wc a"

.PHONY: test
test: all
	./pipex $(TEST_FILE_IN) $(CAT_CMD) $(TEST_0_CMD) result0.txt
	./pipex $(TEST_FILE_IN) $(CAT_CMD) $(TEST_1_CMD) result1.txt
	./pipex $(TEST_FILE_IN) $(CAT_CMD) $(TEST_2_CMD) result2.txt
	./pipex $(TEST_FILE_IN) $(CAT_CMD) $(TEST_3_CMD) result3.txt
	echo "Result 0:\n" && cat result0.txt && echo "\n\n"
	echo "Result 1:\n" && cat result1.txt && echo "\n\n"
	echo "Result 2:\n" && cat result2.txt && echo "\n\n"
	echo "Result 3:\n" && cat result3.txt && echo "\n\n"
	rm result*.txt