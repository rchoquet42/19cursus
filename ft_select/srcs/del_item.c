/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_item.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 23:25:14 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/27 17:31:35 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		del_node(t_argv **tmp, bool b_end)
{
	(*tmp)->next->prev = (*tmp)->prev;
	(*tmp)->prev->next = (*tmp)->next;
	if (b_end == FALSE)
		(*tmp)->next->cursor = 1;
	else
		(*tmp)->prev->cursor = 1;
	free(*tmp);
	(*tmp) = NULL;
	tmp = NULL;
}

static void		set_to_null(t_argv **begin, t_argv **end, t_argv **tmp)
{
	free((*tmp));
	(*begin) = NULL;
	(*end) = NULL;
}

void			del_item(t_argv **begin, t_argv **end, t_maxinfo *max)
{
	t_argv	*tmp;
	bool	b_end;

	max->elem--;
	tmp = (*begin)->prev;
	while ((tmp = tmp->next))
		if (tmp->cursor == 1)
		{
			(tmp->select == 1 ? max->selected-- : 0);
			free(tmp->name);
			if (tmp == (*begin))
			{
				if ((*begin) == (*begin)->next)
					return (set_to_null(begin, end, &tmp));
				else
					(*begin) = tmp->next;
				b_end = FALSE;
			}
			else if (tmp == (*end) && (b_end = TRUE))
				(*end) = tmp->prev;
			if (tmp != NULL && (tmp->prev != tmp && tmp->next != tmp))
				del_node(&tmp, b_end);
			return ;
		}
}
