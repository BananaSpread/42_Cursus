# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/18 13:22:51 by idel-poz          #+#    #+#              #
#    Updated: 2024/04/01 13:53:47 by idel-poz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

SRC = get_next_line.c get_next_line_utils.c
OBJ = $(SRC:.c=.o)

NAME = get_next_line.a

TEST_EXEC_AND_REMOVE_FILE = ./a.out && rm -f a.out
BUFFER_SIZE_DEF = BUFFER_SIZE

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(ARFLAGS) $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) a.out

fclean:	clean
	rm -f $(NAME)

re: fclean $(NAME)

test1: all
	$(CC) $(CFLAGS) main.c ${SRC} && $(TEST_EXEC_AND_REMOVE_FILE)

test2: all
	$(CC) $(CFLAGS) -D $(BUFFER_SIZE_DEF)=0 main.c ${SRC} && $(TEST_EXEC_AND_REMOVE_FILE)

test3: all
	$(CC) $(CFLAGS) -D $(BUFFER_SIZE_DEF)=1 main.c ${SRC} && $(TEST_EXEC_AND_REMOVE_FILE)

test4: all
	$(CC) $(CFLAGS) -D $(BUFFER_SIZE_DEF)=42 main.c ${SRC} && $(TEST_EXEC_AND_REMOVE_FILE)

test5: all
	$(CC) $(CFLAGS) -D $(BUFFER_SIZE_DEF)=10000000 main.c ${SRC} && $(TEST_EXEC_AND_REMOVE_FILE)

.PHONY: all clean fclean re test1 test2 test3 test4 test5