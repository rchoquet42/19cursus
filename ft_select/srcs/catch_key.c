/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 03:32:50 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/27 17:15:39 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	select_item(t_argv **begin, t_maxinfo *max)
{
	t_argv	*tmp;

	tmp = (*begin);
	while (tmp)
	{
		if (tmp->cursor == 1)
		{
			if (tmp->select == 0)
				tmp->select = 1;
			else
			{
				tmp->select = 0;
				max->selected--;
				return ;
			}
			max->selected++;
			tmp->cursor = 0;
			tmp->next->cursor = 1;
			return ;
		}
		tmp = tmp->next;
	}
}

static bool	is_lstempty(t_argv **begin)
{
	if (begin != NULL && (*begin) != NULL)
		return (FALSE);
	return (TRUE);
}

static int	apply_key(t_argv **begin, t_argv **end, long c, t_maxinfo *max)
{
	if (c == ESC)
		return (-1);
	else if (c == ENTER)
		return (1);
	else if (c == SPC)
		select_item(begin, max);
	else if (c == RIGHT)
		go_right(begin, max);
	else if (c == LEFT)
		go_left(begin, max);
	else if (c == UP)
		go_up(end);
	else if (c == DOWN)
		go_down(begin);
	else if (c == DEL || c == BSPC)
		del_item(begin, end, max);
	if (is_lstempty(begin) == TRUE)
		return (-1);
	return (0);
}

bool		catch_key(t_argv **begin, t_argv **end, t_maxinfo *max)
{
	long	c;
	int		tmp;

	while (1)
	{
		c = 0;
		print_argv(begin, end, max);
		read(0, &c, 8);
		tmp = apply_key(begin, end, c, max);
		if (tmp == 1)
			return (TRUE);
		else if (tmp == -1)
			return (FALSE);
	}
}
