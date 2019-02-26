/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_right.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:31:14 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/20 18:25:47 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	go_right(t_argv **begin, t_maxinfo *max)
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
	if (pos + max->line <= max->elem)
		i = max->line;
	else
		i = (max->elem - pos);
	tmp->cursor = 0;
	while (i > 0)
	{
		tmp = tmp->next;
		i--;
	}
	tmp->cursor = 1;
}
