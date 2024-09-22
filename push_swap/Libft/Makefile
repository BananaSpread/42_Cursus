# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idel-poz <idel-poz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/14 18:00:44 by idel-poz          #+#    #+#              #
#    Updated: 2024/09/22 14:17:31 by idel-poz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compilation and flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

AR = ar
ARFLAGS = rcs

# Source files and library filename
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
	ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
	ft_itoa.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memmove.c \
	ft_memset.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c \
	ft_strmapi.c ft_strncmp.c ft_strnstr.c ft_strrchr.c \
	ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
	ft_printf.c ft_printers.c \
	get_next_line.c get_next_line_utils.c

OBJ = $(SRC:.c=.o)

NAME = libft.a

# Functions
all: $(NAME)
	@echo "libft compiled successfully."

$(NAME): $(OBJ)
	@$(AR) $(ARFLAGS) $(NAME) $^

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
