# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcortina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 13:11:26 by gcortina          #+#    #+#              #
#    Updated: 2016/11/18 15:11:38 by gcortina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXE = ft_printf
HEADER = ./include/
SRCDIR = ./src/
FLAGS = -Wall -Wextra -Werror
CC = gcc
OPTIONS = -c -I $(HEADER) $(FLAGS)
RLIB = ranlib
SRC_FILES = ft_printf.c main.c
SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
OBJ_NAME = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(OPTIONS) $(SRCS)
	ar rc $(NAME) $(OBJ_NAME)
	$(RLIB) $(NAME)

run:
	$(CC) -I $(HEADER) $(SRCS) -o $(EXE)

clean:
	rm -f $(OBJ_NAME)

fclean: clean
	rm -f $(NAME) $(EXE)

re: fclean all

