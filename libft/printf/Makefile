# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerahmou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:17:07 by nerahmou          #+#    #+#              #
#    Updated: 2018/06/06 19:41:03 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean
.SUFFIXES:
	blue = echo "\x1b[47m\x1b[32m\#\# $1 \#\# \x1b[0m \n"

NAME = printf
CC = gcc
CFLAGS =  -Wall -Wextra -Werror

SRC_PATH = ./srcs
INC_PATH = ./include
OBJ_PATH = ../obj

SRC_NAME =	ft_printf.c\
			get_attributs.c \
			check_attributs.c \
			check_color_style.c \
			get_ret_value.c \
			print.c \
			print_s.c \
			print_ws.c \
			print_c.c \
			print_d.c \
			print_b.c \
			print_o.c \
			print_u.c \
			print_x.c \
			print_p.c \
			print_m.c \
			nbr_size.c

INC_NAME = ft_printf.h

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
INC = $(addprefix $(INC_PATH)/, $(INC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ) $(INC)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -rf
	@echo "\033[1;34mft_printf\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all
