# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gcortina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/17 13:11:26 by gcortina          #+#    #+#              #
#    Updated: 2016/11/17 13:43:09 by gcortina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ./include/
SRCDIR = ./src/
FLAGS = -Wall -Wextra -Werror
CC = gcc
OPTIONS = -c -I $(HEADER) $(FLAGS)
RLIB = ranlib
SRC = ft_printf.c
