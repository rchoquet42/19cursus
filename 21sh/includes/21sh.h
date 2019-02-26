/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:01:04 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/17 21:36:46 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S21SH_H
# define S21SH_H
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <term.h>
# include <curses.h>
# include "libft.h"
# include <stdbool.h>
# include <sys/ioctl.h>
# include <sys/stat.h>

# define CMD_CHAR	19
# define BUF_SIZE	50
# define ENTER 10
# define ESC 27
# define SPC 32
# define LEFT 4479771
# define UP 4283163
# define RIGHT 4414235
# define DOWN 4348699
# define DEL 2117294875
# define BSPC 127

# define SET_P 0
# define GET_P 1
# define DEL_P 2

/*
** prompt.c
*/

char	*get_prompt(void);
void	set_prompt(char *msg);
void	del_prompt(void);
void	display_prompt(void);

/*
** catch_key.c
*/

void	read_line(void);

/*
** init.c
*/

int		init_all(void);

/*
** signal.c
*/

void	sig_end(int sig_num);

/*
** display.c
*/

int		env_not_found(void);

#endif

