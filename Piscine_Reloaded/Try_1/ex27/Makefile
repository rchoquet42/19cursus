# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/12 15:19:54 by rchoquet          #+#    #+#              #
#    Updated: 2018/06/12 15:40:49 by rchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
FLAGS = -Wall -Wextra -Werror
SRC = ft_read.c 
OBJ = ft_read.o
NAME = ft_display_file

all:
	make $(NAME)

$(NAME):
	$(C) $(FLAGS) -c $(SRC)
	$(C) $(OBJ) main.c -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
