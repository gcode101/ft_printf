# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcortina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 13:11:26 by gcortina          #+#    #+#              #
#    Updated: 2016/12/12 13:53:59 by gcortina         ###   ########.fr        #
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
SRC_FILES = ft_printf.c main.c str_conv.c format_reader.c get_flags.c get_len_flag.c \
			get_pre.c handle_width.c ft_putwchar.c handle_wchar.c get_width.c \
			handle_flags.c chr_conv.c ft_wstrsub.c ft_wstrlen.c ft_wmemset.c \
			handle_wchar_width.c handle_wchar_str.c ft_wstrdup.c handle_wflags.c \
			decimal_conv.c zero_flag.c handle_dec_lenflag.c ft_itoa_base.c octal_conv.c \
			modify_arg.c hex_conv.c unsigned_conv.c handle_un_lenflag.c chr_count.c
LIB_FILES = ft_putstr.c ft_putchar.c ft_putendl.c ft_atoi.c ft_memdel.c ft_strchr.c \
			ft_isdigit.c ft_strdup.c ft_strjoin.c ft_strlen.c ft_strnew.c ft_strsub.c \
			ft_memset.c ft_isascii.c ft_bzero.c ft_strcmp.c ft_itoa.c ft_putnbr.c \
			ft_strcpy.c ft_toupper.c
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
	$(CC) -I $(HEADER) $(FLAGS) $(SRCS) $(LIB_SRCS) -o $(EXE)

clean:
	rm -f $(OBJ_NAME) $(OBJLIB_NAME)

fclean: clean
	rm -f $(NAME) $(EXE)

re: fclean all

