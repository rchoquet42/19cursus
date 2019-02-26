# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 15:49:01 by rchoquet          #+#    #+#              #
#    Updated: 2018/09/30 01:06:31 by rchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

LIB = -L./lib_dir -lft -lftprintf

LIB_DIR = lib_dir
FLAGS = -Wall -Wextra -Werror
#FLAGS = -fsanitize=address

SRCS = options.c stat.c list.c display_lst.c sort_argv.c free.c utils.c\
	   sort_list.c display_basic.c display_utils.c free_utils.c\
	   stat_time.c stat_right.c ft_ls.c
OBJ = options.o stat.o list.o display_lst.o sort_argv.o free.o utils.o\
	  sort_list.o display_basic.o display_utils.o free_utils.o\
	  stat_time.o stat_right.o ft_ls.o
#SRCS = *.c
#OBJ = *.o

PATH_SRCS = srcs/
PATH_INCLUDES = -I includes/ -I libft/includes/
PATH_OBJ = objs/
NAME = ./ft_ls
OBJ_PATH = $(addprefix $(PATH_OBJ), $(OBJ))
SRCS_PATH = $(addprefix $(PATH_SRCS), $(SRCS))

all: $(NAME)

$(NAME): $(SRCS_PATH)
	afplay songs/start.mp3 & sleep 0.01
	make -C libft
	mkdir $(LIB_DIR)
	cp libft/libft.a $(LIB_DIR)
	cp libft/libftprintf.a $(LIB_DIR)
	$(C) -I ./libft/includes/ -I ./includes -c $(SRCS_PATH)
	mkdir objs
	mv $(OBJ) $(PATH_OBJ)
	$(C) $(FLAGS) $(PATH_INCLUDES) $(OBJ_PATH) $(LIB) srcs/main.c -o $(NAME)
	afplay songs/cym.mp3 & sleep 0.1
	
clean:
	make clean -C libft
	rm -rf $(LIB_DIR)
	rm -rf $(PATH_OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
