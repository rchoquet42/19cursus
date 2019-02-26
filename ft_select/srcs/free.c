/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 17:38:43 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/26 18:41:22 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	free_linked_max(t_argv **begin, t_argv **end, t_maxinfo **max)
{
	t_argv	*save;
	int		i;

	i = 0;
	if (begin != NULL && (*begin) != NULL)
	{
		while ((*max)->elem > 0)
		{
			save = (*begin)->next;
			ft_strdel(&((*begin)->name));
			free(*begin);
			(*begin) = save;
			(*max)->elem--;
		}
		end = NULL;
		begin = NULL;
		free(*max);
		max = NULL;
	}
}
