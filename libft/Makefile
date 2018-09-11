# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nerahmou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/07 09:17:07 by nerahmou          #+#    #+#              #
#    Updated: 2018/09/11 09:44:19 by nerahmou    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #

.PHONY: all clean fclean re make_printf
.SUFFIXES:

_END=$'\x1b[0m
_BOLD=$'\x1b[1m
_UNDER=$'\x1b[4m
_ICYAN=$'\x1b[46m
_IGREY=$'\x1b[40m
_IRED=$'\x1b[41m
_IGREEN=$'\x1b[42m
_IYELLOW=$'\x1b[43m

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_memchr.c\
		ft_putstr.c\
		ft_strjoin.c\
		ft_strsplit.c\
		ft_memcmp.c\
		ft_putstr_fd.c\
		ft_strlcat.c\
		ft_strstr.c \
		ft_atoi.c\
		ft_memcpy.c\
		ft_strcat.c\
		ft_strlen.c\
		ft_strsub.c\
		ft_bzero.c\
		ft_memdel.c\
		ft_strchr.c\
		ft_strmap.c\
		ft_strtrim.c\
		ft_isalnum.c\
		ft_memmove.c\
		ft_strclr.c\
		ft_strmapi.c\
		ft_tolower.c\
		ft_isalpha.c\
		ft_memset.c\
		ft_strcmp.c\
		ft_strncat.c\
		ft_toupper.c\
		ft_isascii.c\
		ft_countwords.c\
		ft_putchar.c\
		ft_strcpy.c\
		ft_strncmp.c\
		ft_isdigit.c\
		ft_putchar_fd.c\
		ft_strdel.c\
		ft_strncpy.c\
		ft_isprint.c\
		ft_ischar.c\
		ft_putendl.c\
		ft_strdup.c\
		ft_strnequ.c\
		ft_itoa.c\
		ft_putendl_fd.c\
		ft_strequ.c\
		ft_strnew.c\
		ft_memalloc.c\
		ft_putnbr.c\
		ft_putnbrendl.c\
		ft_striter.c\
		ft_strnstr.c\
		ft_memccpy.c\
		ft_putnbr_fd.c\
		ft_striteri.c\
		ft_strrchr.c\
		ft_lstadd.c\
		ft_lstdel.c\
		ft_lstdelone.c\
		ft_lstiter.c\
		ft_lstmap.c\
		ft_lstnew.c\
		ft_swap.c\
		ft_list_size.c\
		ft_foreach.c\
		ft_sqrt.c\
		ft_lstclear.c\
		ft_char_pos.c\
		ft_itoa_base.c\
		ft_abs.c\
		ft_atoierr.c\
		ft_putnbr_base.c\
		ft_putwchar.c\
		ft_putwstr.c\
		ft_wstrlen.c\
		ft_intlen.c\
		ft_uintlen.c\
		ft_wcharlen.c\
		ft_lstlen.c\
		ft_strchr_occur.c\
		ft_tablength.c

SRC_PRF =	ft_printf.c\
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

OBJ_PATH = ./obj

OBJ_NAME = $(SRC:.c=.o)
OBJ_NAME += $(SRC_PRF:.c=.o)

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

INC = libft.h

all: $(NAME)

$(NAME): make_printf $(OBJ) $(INC)
	@ar rcs $(NAME) $(OBJ)
	@echo "Library created 👍 \n"

$(OBJ_PATH)/%.o: %.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	@echo "COMPILATION DE ($(_BOLD)$(_IRED)$(notdir $<)$(_END)) EN ($(_BOLD)$(_IGREEN)$(notdir $@)$(_END))"
	@$(CC) $(CFLAGS) -c $^ -o $@
	@clear

make_printf:
	@make -C printf

clean:
	@rm -rf $(OBJ_PATH)
	@echo	"Clean libft O.K.\n"
	
fclean: clean
	@rm -f $(NAME)
	@echo	"Fclean libft O.K.\n"

re: fclean all
