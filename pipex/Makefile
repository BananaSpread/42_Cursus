# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/18 12:42:32 by idel-poz          #+#    #+#              #
#    Updated: 2024/09/09 20:44:03 by idel-poz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = pipex.c fill_data.c cmd_utils.c exec_cmd.c
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
TEST_3_CMD = "wc -w"

.PHONY: test
test: all
	./pipex $(TEST_FILE_IN) $(CAT_CMD) $(TEST_0_CMD) result0.txt
	./pipex $(TEST_FILE_IN) $(CAT_CMD) $(TEST_1_CMD) result1.txt
	./pipex $(TEST_FILE_IN) $(CAT_CMD) $(TEST_2_CMD) result2.txt
	touch emptyfile && ./pipex emptyfile env_var cat result3.txt && rm emptyfile
	./pipex $(TEST_FILE_IN) "ping -c 3 google.es" cat result4.txt
	@echo "Result 0:" && cat result0.txt && echo ""
	@echo "Result 1:" && cat result1.txt && echo ""
	@echo "Result 2:" && cat result2.txt && echo ""
	@echo "Result 3:" && cat result3.txt && echo ""
	@echo "Result 4:" && cat result4.txt && echo ""
	rm result*.txt

.PHONY: leaks1 leaks2
leaks1: all
	valgrind --leak-check=full ./pipex pipex.c cat "wc -l" result_leak0.txt

leaks2: all
	valgrind --leak-check=full --show-reachable=yes ./pipex pipex.c cat ff result_leak1.txt