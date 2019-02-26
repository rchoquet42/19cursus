/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 16:51:03 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/12 22:33:45 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_color(char *str)
{
	char	*tabcol[9];
	int		i;

	tabcol[0] = "BLACK;\033[30m";
	tabcol[1] = "RED;\033[31m";
	tabcol[2] = "GREEN;\033[32m";
	tabcol[3] = "YELLOW;\033[33m";
	tabcol[4] = "BLUE;\033[34m";
	tabcol[5] = "PURPLE;\033[35m";
	tabcol[6] = "CYAN;\033[36m";
	tabcol[7] = "WHITE;\033[37m";
	tabcol[8] = NULL;
	i = 0;
	while (tabcol[i])
	{
		if (ft_strcmp_char(str, tabcol[i], ';') == 0)
		{
			return (ft_strchr(tabcol[i], ';'));
		}
		i++;
	}
	return (NULL);
}

void		display_prompt(void)
{
	char	*tmp;
	char	*color;

	color = get_value("PCOLOR");
	if (color == NULL)
	{
		color = "CYAN";
		ft_setenv("PCOLOR", "CYAN");
	}
	if ((tmp = get_value("USER")) == NULL)
		tmp = "$";
	color = get_color(color);
	color++;
	ft_printf("%s%s>%s", color, tmp, DEFAULT);
}

void		build_setpcolor(char **cmd)
{
	char	*color;

	if (cmd[1] == NULL)
		return (ft_setenv("PCOLOR", "CYAN"));
	else
	{
		if ((color = get_color(cmd[1])) == NULL)
		{
			ft_putstr_fd("setpcolor: BLACK RED GREEN", 2);
			ft_putstr_fd(" YELLOW BLUE PURPLE CYAN WHITE\n", 2);
		}
		else
			ft_setenv("PCOLOR", cmd[1]);
	}
}
