# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 16:07:32 by rchoquet          #+#    #+#              #
#    Updated: 2018/09/24 18:48:06 by rchoquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft.a
PRINTF = libftprintf.a
PATH_LIBFT = srcs/libft/
PATH_PRINTF = srcs/ft_printf/

all:
	make $(LIB)
	make $(PRINTF)

$(LIB):
	make -C $(PATH_LIBFT)
	cp srcs/libft/libft.a .

$(PRINTF):
	make -C $(PATH_PRINTF)
	cp srcs/ft_printf/libftprintf.a .

clean:
	make clean -C $(PATH_LIBFT)
	make clean -C $(PATH_PRINTF)

fclean: clean
	rm -f $(PRINTF)
	rm -f $(LIB)
	make fclean -C $(PATH_LIBFT)
	make fclean -C $(PATH_PRINTF)

re: fclean all

.PHONY: all re clean fclean
