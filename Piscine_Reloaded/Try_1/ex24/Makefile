# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 14:09:15 by rchoquet          #+#    #+#              #
#    Updated: 2018/06/12 14:30:28 by rchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
FLAGS = -Wall -Wextra -Werror
SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
I = ./includes
NAME = libft.a

all:
	make $(NAME)

$(NAME):
	$(C) $(FLAG) -I./includes -c $(SRC)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
