# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcortina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 13:11:26 by gcortina          #+#    #+#              #
#    Updated: 2016/11/19 14:45:30 by gcortina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXE = ft_printf
HEADER = ./include/
SRCDIR = ./src/
LIBDIR = ./lib/
FLAGS = -Wall -Wextra -Werror
CC = gcc
OPTIONS = -c -I $(HEADER) $(FLAGS)
RLIB = ranlib
SRC_FILES = ft_printf.c main.c
LIB_FILES = ft_putstr.c ft_putchar.c ft_putendl.c
SRCS = $(addprefix $(SRCDIR), $(SRC_FILES))
LIB_SRCS = $(addprefix $(LIBDIR), $(LIB_FILES))
OBJ_NAME = $(SRC_FILES:.c=.o)
OBJLIB_NAME = $(LIB_FILES:.c=.o)

all: $(NAME)

$(NAME):
	$(CC) $(OPTIONS) $(SRCS) $(LIB_SRCS)
	ar rc $(NAME) $(OBJ_NAME) $(OBJLIB_NAME)
	$(RLIB) $(NAME)

run:
	$(CC) -I $(HEADER) $(SRCS) $(LIB_SRCS) -o $(EXE)

clean:
	rm -f $(OBJ_NAME) $(OBJLIB_NAME)

fclean: clean
	rm -f $(NAME) $(EXE)

re: fclean all

