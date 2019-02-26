/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:22:18 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/29 14:47:33 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <fcntl.h>
# include "libft.h"

typedef struct		s_block
{
	short			**block;
	char			letter;
	short			height;
	struct s_block	*next;
}					t_block;

/*
** is_valid.c
*/
typedef struct		s_valid
{
	int nb_block;
	int	nb_space;
	int	line;
	int	side;
}					t_valid;

t_valid				init_info(void);

int					is_valid(char *buf, int ret);
void				valid_char(char c, t_valid *ptr);
void				valid_side(int pos, char *buf, t_valid *ptr);

/*
**	to_coord.c
*/
short				**to_coord(char *tetris);
void				set_x_0(int i, short **tab);
void				set_x(int i, int x, short **tab);

/*
**	lst_pushback.c
*/
void				lst_pushback(t_block **begin, short **coord);
t_block				*lst_create(short **coord);
void				lst_free(t_block **begin);

/*
**	read_file.c
*/
int					read_file(char **argv, t_block **begin);

/*
** errror.c
*/
int					error(t_block **begin);

/*
** new_map.c
*/
int					sizeof_map(int count);
int					ft_sqrt(int nbr);
char				*new_map(int nbr);

/*
**	fillit.c
*/
int					fillit(t_block *node, char *res);
int					is_free(short **block, int pos, char *res);
char				*fill_res(t_block *node, int pos, char *res);
void				unfill(char *res, int pos, short **block);

/*
**	display.c
*/
void				display(char *res, int size_map);

#endif
