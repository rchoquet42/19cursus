# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/30 11:38:38 by rchoquet          #+#    #+#              #
#    Updated: 2018/08/30 11:40:21 by rchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

SRC = fillit.c new_map.c to_coord.c display.c read_file.c error.c is_valid.c lst_pushback.c

OBJ = fillit.o new_map.o to_coord.o display.o read_file.o error.o is_valid.o lst_pushback.o

CC = gcc

FLAGS = -Werror -Wall -Wextra

main = main.c

all: $(NAME)

$(NAME):
	@make -C libft
	@$(CC) $(FLAGS) -I./libft -c $(SRC)
	@$(CC) $(FLAGS) $(OBJ) -I./libft main.c -Llibft -lft -o $(NAME)

clean:
	@make clean -C libft
	@rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)

re: fclean all

.PHONY: all $(NAME) clean fclean re
