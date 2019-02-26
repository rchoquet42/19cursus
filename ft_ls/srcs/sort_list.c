/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 18:57:04 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/29 16:16:45 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_alphanum(t_info *node, t_info **begin, t_info **end)
{
	t_info	*tmp;
	t_info	*save;

	tmp = (*begin);
	while (tmp)
	{
		if (ft_strcmp(node->name, tmp->name) < 0)
		{
			node_swap(&node, &tmp, begin, end);
			return ;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		(*end)->next = node;
		node->prev = (*end);
		(*end) = node;
	}
}

void		node_swap(t_info **node, t_info **tmp, t_info **begin, t_info **end)
{
	t_info	*save;

	if ((*tmp)->prev == NULL)
	{
		(*begin) = (*node);
		(*node)->next = (*tmp);
		(*tmp)->prev = (*node);
	}
	else
	{
		save = (*tmp)->prev;
		(*node)->next = (*tmp);
		(*tmp)->prev = (*node);
		save->next = (*node);
		(*node)->prev = save;
	}
}

void		sort_time(t_info *node, t_info **begin, t_info **end)
{
	t_info	*tmp;
	t_info	*save;

	tmp = (*begin);
	while (tmp)
	{
		if (node->time > tmp->time)
		{
			node_swap(&node, &tmp, begin, end);
			return ;
		}
		if ((node->time == tmp->time) && ft_strcmp(node->name, tmp->name) <= 0)
		{
			node_swap(&node, &tmp, begin, end);
			return ;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		(*end)->next = node;
		node->prev = (*end);
		(*end) = node;
	}
}

void		sort_size(t_info *node, t_info **begin, t_info **end)
{
	t_info	*tmp;
	t_info	*save;

	tmp = (*begin);
	while (tmp)
	{
		if (node->size > tmp->size)
		{
			node_swap(&node, &tmp, begin, end);
			return ;
		}
		if ((node->size == tmp->size) && ft_strcmp(node->name, tmp->name) <= 0)
		{
			node_swap(&node, &tmp, begin, end);
			return ;
		}
		tmp = tmp->next;
	}
	if (tmp == NULL)
	{
		(*end)->next = node;
		node->prev = (*end);
		(*end) = node;
	}
}
