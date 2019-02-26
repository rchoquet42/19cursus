/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 15:13:35 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/22 23:52:36 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	unlink_node(t_info *node)
{
	t_info *save_prev;
	t_info *save_next;

	save_prev = node->prev;
	save_next = node->next;
	save_prev->next = save_next;
	save_next->prev = save_prev;
}

void	set_node_to_null(t_info **node1, t_info **node2)
{
	if (node1 != NULL)
		*node1 = NULL;
	if (node2 != NULL)
		*node2 = NULL;
}

int		update_head_tail(t_info *tmp, t_info **begin, t_info **end)
{
	int	i;

	i = 0;
	if (tmp == (*begin))
	{
		tmp->next->prev = NULL;
		(*begin) = (*begin)->next;
		i = 1;
	}
	else if (tmp == (*end))
	{
		tmp->prev->next = NULL;
		(*end) = (*end)->prev;
		i = 1;
	}
	return (i);
}

int		free_node_alone(t_info *info)
{
	free(info->path);
	free(info);
	info = NULL;
	return (1);
}
