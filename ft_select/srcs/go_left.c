/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_left.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:40:45 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/20 18:26:08 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	go_left(t_argv **begin, t_maxinfo *max)
{
	int		i;
	int		pos;
	t_argv	*tmp;

	pos = 1;
	tmp = (*begin);
	while (tmp->cursor != 1)
	{
		pos++;
		tmp = tmp->next;
	}
	if (pos - max->line > 0)
		i = max->line;
	else
		i = pos - 1;
	tmp->cursor = 0;
	while (i > 0)
	{
		tmp = tmp->prev;
		i--;
	}
	tmp->cursor = 1;
}
