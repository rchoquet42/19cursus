/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 04:04:53 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/27 17:35:37 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	choose_color(t_argv *tmp)
{
	if (tmp->type == 'd')
		ft_putstr_fd(GREEN, 0);
	else if (tmp->type == 'x')
		ft_putstr_fd(RED, 0);
}

void		display_select(t_argv **begin, t_argv **end, t_maxinfo *max)
{
	t_argv	*tmp;
	int		x;
	int		y;

	x = 0;
	y = 0;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_putstr_fd(tgetstr("vi", NULL), 0);
	tmp = (*begin);
	while (1)
	{
		gotoxy(x, y);
		choose_color(tmp);
		(tmp->select == 1 ? ft_putstr_fd(tgetstr("mr", NULL), 0) : 0);
		(tmp->cursor ? ft_putstr_fd(tgetstr("us", NULL), 0) : 0);
		ft_printf_fd(0, "%s", tmp->name);
		ft_printf_fd(0, "%s", tgetstr("me", NULL));
		if (tmp == (*end))
			break ;
		y += 1;
		x += (y == (max->line) ? max->startcol : 0);
		y = (y == (max->line) ? 0 : y);
		tmp = tmp->next;
	}
}

void		display_argv(t_argv **begin, t_maxinfo *max)
{
	t_argv	*tmp;
	int		i;

	i = 0;
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_printf_fd(0, "%s", tgetstr("me", NULL));
	tmp = (*begin);
	while (tmp)
	{
		if (tmp->select == 1)
		{
			ft_printf_fd(1, "%s", tmp->name);
			max->selected--;
			i = 1;
			if (max->selected > 0)
				ft_printf_fd(1, " ");
		}
		tmp = tmp->next;
		if (tmp == (*begin))
		{
			if (i == 1 && max->selected == 0)
				ft_printf_fd(1, "\n");
			return ;
		}
	}
}

void		display_toosmall(void)
{
	ft_putstr_fd(tgetstr("cl", NULL), 0);
	ft_printf_fd(0, "Not enough space\n");
}

int			env_not_found(void)
{
	ft_printf_fd(2, "ERROR : Env not found\n");
	return (1);
}
