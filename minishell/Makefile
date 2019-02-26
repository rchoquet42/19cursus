# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/06 15:49:01 by rchoquet          #+#    #+#              #
#    Updated: 2018/10/19 00:27:08 by rchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc

LIB = -L./lib_dir -lft -lftprintf

LIB_DIR = lib_dir
#FLAGS = -Wall -Wextra -Werror
#FLAGS = -fsanitize=address

SRCS = init.c exec.c interpreter.c env.c free.c display.c echo.c ft_split_argv.c\
	   utils.c setenv.c unsetenv.c cd.c signal.c resetenv.c display_error.c\
	   bracket_quote.c prompt.c
OBJ = init.o exec.o interpreter.o env.o free.o display.o echo.o ft_split_argv.o\
	  utils.o setenv.o unsetenv.o cd.o signal.o resetenv.o display_error.o\
	  bracket_quote.o prompt.o
	  
#SRCS = *.c
#OBJ = *.o

PATH_SRCS = srcs/
PATH_INCLUDES = -I includes/ -I libft/includes/
PATH_OBJ = objs/
NAME = ./minishell
OBJ_PATH = $(addprefix $(PATH_OBJ), $(OBJ))
SRCS_PATH = $(addprefix $(PATH_SRCS), $(SRCS))

all: $(NAME)

$(NAME): $(SRCS_PATH)
	make -C libft
	mkdir $(LIB_DIR)
	cp libft/libft.a $(LIB_DIR)
	cp libft/libftprintf.a $(LIB_DIR)
	$(C) -I ./libft/includes/ -I ./includes -c $(SRCS_PATH)
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
