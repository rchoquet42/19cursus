/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_down.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:32:39 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/20 18:25:27 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	go_down(t_argv **begin)
{
	t_argv	*tmp;

	tmp = (*begin);
	while (tmp)
	{
		if (tmp->cursor == 1)
		{
			tmp->cursor = 0;
			tmp->next->cursor = 1;
			return ;
		}
		tmp = tmp->next;
	}
}
