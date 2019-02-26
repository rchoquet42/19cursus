/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 00:26:57 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/26 19:35:22 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <term.h>
# include <curses.h>
# include <stdio.h>
# include "libft.h"
# include <stdbool.h>
# include <sys/ioctl.h>
# include <sys/stat.h>

# define RSTCOLOR "\033[0m"
# define GREEN "\033[0;32m"
# define BLUE "\033[0;34m"
# define RED "\033[0;31m"
# define ENTER 10
# define ESC 27
# define SPC 32
# define LEFT 4479771
# define UP 4283163
# define RIGHT 4414235
# define DOWN 4348699
# define DEL 2117294875
# define BSPC 127

typedef	struct	s_argv
{
	bool			cursor;
	char			type;
	char			*name;
	bool			select;
	struct s_argv	*next;
	struct s_argv	*prev;
}				t_argv;

typedef	struct	s_maxinfo
{
	size_t			max_len;
	int				elem;
	int				selected;
	size_t			startcol;
	int				line;
	int				col;
}				t_maxinfo;

/*
** free.c
*/

void			free_linked_max(t_argv **begin, t_argv **end, t_maxinfo **max);

/*
** usage.c
*/

int				usage(void);

/*
** init.c
*/

int				init_all(t_argv **begin, t_argv **end, t_maxinfo **max);

/*
** create_chain.c
*/

t_maxinfo		*create_chain(t_argv **begin, t_argv **end, char **argv);

/*
** catch_key.c
*/

bool			catch_key(t_argv **begin, t_argv **end, t_maxinfo *max);

/*
** del_item.c
*/

void			del_item(t_argv **begin, t_argv **end, t_maxinfo *max);

/*
** display.c
*/

void			display_select(t_argv **begin, t_argv **end, t_maxinfo *max);
void			display_argv(t_argv **begin, t_maxinfo *max);
void			display_toosmall(void);
int				env_not_found(void);

/*
** util.c
*/

void			gotoxy(int x, int y);
t_argv			**save_begin(t_argv **begin_par);
t_argv			**save_end(t_argv **end_par);
t_maxinfo		**save_max(t_maxinfo **max_par);

/*
** winsize.c
*/

bool			check_winsize(t_maxinfo *max);
bool			change_winsize(void);

/*
** print_argv.c
*/

bool			print_argv(t_argv **begin, t_argv **end, t_maxinfo *max);

/*
** go_*.c
*/

void			go_down(t_argv **begin);
void			go_up(t_argv **end);
void			go_right(t_argv **begin, t_maxinfo *max);
void			go_left(t_argv **begin, t_maxinfo *max);

/*
** sig_handler.c
*/

void			sig_end(int sig_num);
void			sig_winch(int sig_num);
void			sig_suspend(int sig_num);
void			sig_restart(int sig_num);

#endif
