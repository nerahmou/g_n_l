# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerahmou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:17:07 by nerahmou          #+#    #+#              #
#    Updated: 2017/12/05 07:39:55 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean
.SUFFIXES:

NAME = exec
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = main.c get_next_line.c
OBJ = $(SRC:.c=.o)

all: $(NAME)
	
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -L./libft -lft -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
