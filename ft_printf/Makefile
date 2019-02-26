# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/02 16:03:16 by rchoquet          #+#    #+#              #
#    Updated: 2018/08/30 18:24:45 by rchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = gcc
SRC = conversion.c flags.c ft_printf.c itoa_base.c length.c precision.c\
	  width.c display.c flags_options.c ft_unicode_conv.c init.c util.c

SRCP = printf_char.c printf_decimal.c printf_hexa.c printf_hexa_cap.c\
	   printf_ldecimal.c printf_loctal.c printf_ludecimal.c printf_octal.c\
	   printf_ptr.c printf_string.c printf_udecimal.c printf_wchar_t.c\
	   printf_wint_t.c printf_binaire.c printf_pourcent.c printf_do_nothing.c

OBJ = conversion.o flags.o ft_printf.o itoa_base.o length.o precision.o\
	  printf_char.o printf_decimal.o printf_hexa.o printf_hexa_cap.o\
	  printf_ldecimal.o printf_loctal.o printf_ludecimal.o printf_octal.o\
	  printf_ptr.o printf_string.o printf_udecimal.o width.o\
	  printf_wchar_t.o printf_wint_t.o display.o flags_options.o\
	  printf_pourcent.o printf_do_nothing.o ft_unicode_conv.o init.o util.o\
	  printf_binaire.o
LIB_PATH = ./libft
LIB_OBJ =  /ft_atoi.o /ft_isdigit.o /ft_itoa.o /ft_memalloc.o  /ft_memset.o\
		   /ft_putchar.o /ft_putstr.o /ft_strcat.o /ft_strcmp.o  /ft_strcpy.o\
		   /ft_strdup.o /ft_strjoin.o  /ft_strlcat.o  /ft_strlen.o\
		   /ft_strncpy.o /ft_strnew.o  /ft_strsub.o /ft_tolower.o\
		   /ft_toupper.o /getlocale.o
NAME =  libftprintf.a
LIB_PATH_OBJ = $(addprefix $(LIB_PATH), $(LIB_OBJ))

all: $(NAME)

$(NAME): $(LIB_PATH_OBJ)
	@make cco -C libft
	@$(C) -c $(SRC) $(SRCP)
	@ar rc $(NAME) $(OBJ) $(LIB_PATH_OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ)
	@make clean -C libft

fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft

re: fclean all

.PHONY: all $(NAME) clean fclean re
