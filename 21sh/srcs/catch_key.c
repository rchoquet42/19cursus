/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 14:49:13 by rchoquet          #+#    #+#             */
/*   Updated: 2019/02/04 13:33:01 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int check_char(long c, int i)
{
	if (c == LEFT)
		go_left(); //bouger curseur gauche
	if (c == RIGHT)
		return (0); // "" droite
	if (c == UP)
		return (0);// histo
	if (c == DOWN) // ""
		return (0);
/*	if (c == HOME) //debut de ligne
		return (0);
	if (c == END) //fin de ligne
		return (0);
	if (c == CTRL_LEFT)
		return (0); //1 mot vers la gauche
	if (c == CTRL_RIGHT)
		return (0); //1 mot vers la droite
*/
	return (0);
}

void	read_line(void)
{
	long	c;
	int		i;
	char	line_buf[BUF_SIZE];
	char	*line_malloc;

	c = 0;
	line_malloc = NULL;
	i = 0;
	while (read(STDIN_FILENO, &c, 8) > 0)
	{
		if (c == ENTER)
		{
			line_buf[i] = '\0';
			line_malloc = (line_malloc == NULL ? ft_strdup(line_buf) :
			ft_strjoin_and_free1(line_malloc, line_buf));
			ft_printf("%s\n", line_malloc); // lancer les cmds
			display_prompt();
			ft_strdel(&line_malloc);
			i = 0;
			continue ;
		}
		if (check_char(c, i) == CMD_CHAR)
			continue ;
		line_buf[i++] = c;
		if (i == (BUF_SIZE))
		{
			line_buf[i] = '\0';
			line_malloc = (line_malloc == NULL ? ft_strdup(line_buf) :
			ft_strjoin_and_free1(line_malloc, line_buf));
			i = 0;
		}
	}
}


