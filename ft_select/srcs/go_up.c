/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   go_up.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 12:34:35 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/20 18:24:38 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	go_up(t_argv **end)
{
	t_argv	*tmp;

	tmp = (*end);
	while (tmp)
	{
		if (tmp->cursor == 1)
		{
			tmp->cursor = 0;
			tmp->prev->cursor = 1;
			return ;
		}
		tmp = tmp->prev;
	}
}
