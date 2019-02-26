# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 15:49:01 by rchoquet          #+#    #+#              #
#    Updated: 2018/11/27 18:32:54 by rchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

LIB = -L./lib_dir -lft -lftprintf -ltermcap

LIB_DIR = lib_dir
#FLAGS =
FLAGS = -Wall -Wextra -Werror
#FLAGS = -fsanitize=address

SRCS = usage.c init.c create_chain.c catch_key.c display.c del_item.c winsize.c\
	   util.c print_argv.c go_down.c go_up.c go_right.c go_left.c sig_handler.c\
	   free.c
OBJ = usage.o init.o create_chain.o catch_key.o display.o del_item.o winsize.o\
	  util.o print_argv.o go_down.o go_up.o go_right.o go_left.o sig_handler.o\
	  free.o
	  
#SRCS = *.c
#OBJ = *.o

PATH_SRCS = srcs/
PATH_INCLUDES = -I includes/ -I libft/includes/
PATH_OBJ = objs/
NAME = ./ft_select
OBJ_PATH = $(addprefix $(PATH_OBJ), $(OBJ))
SRCS_PATH = $(addprefix $(PATH_SRCS), $(SRCS))

all: $(NAME)

$(NAME): $(SRCS_PATH)
	make -C libft
	mkdir $(LIB_DIR)
	cp libft/libft.a $(LIB_DIR)
	cp libft/libftprintf.a $(LIB_DIR)
	$(C) $(FLAGS) -I ./libft/includes/ -I ./includes -c $(SRCS_PATH)
	mkdir objs
	mv $(OBJ) $(PATH_OBJ)
	$(C) $(FLAGS) $(PATH_INCLUDES) $(OBJ_PATH) $(LIB) srcs/main.c -o $(NAME)
	
clean:
	make clean -C libft
	rm -rf $(LIB_DIR)
	rm -rf $(PATH_OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
