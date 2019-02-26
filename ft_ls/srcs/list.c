/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 18:22:35 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/29 18:06:06 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_info		*list_new(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (NULL);
	info->prev = NULL;
	info->next = NULL;
	info->sub_begin = NULL;
	info->sub_end = NULL;
	info->path = ft_strdup("");
	info->name = NULL;
	info->right = NULL;
	info->uid = NULL;
	info->month = NULL;
	info->day = NULL;
	info->hour = NULL;
	info->name_lnk = NULL;
	info->acl_c = ' ';
	return (info);
}

t_error		*list_error_new(char *str)
{
	t_error	*node;

	if (!(node = (t_error*)malloc(sizeof(t_error))))
		return (NULL);
	node->erno = errno;
	if (!(node->name = ft_strdup(str)))
		return (NULL);
	node->next = NULL;
	return (node);
}

void		list_add(t_info *node, t_info **begin, t_info **end)
{
	if ((*begin) == NULL)
	{
		(*begin) = node;
		(*end) = node;
		return ;
	}
	if (g_options & OPT_LT)
		sort_time(node, begin, end);
	else if (g_options & OPT_US)
		sort_size(node, begin, end);
	else
		sort_alphanum(node, begin, end);
}

static bool	is_begin(t_error **begin, t_error *node)
{
	if (ft_strcmp((*begin)->name, node->name) >= 0)
	{
		node->next = (*begin);
		(*begin) = node;
		return (1);
	}
	return (0);
}

void		lst_error(char *str, t_error **begin, t_max *max)
{
	t_error	*node;
	t_error	*tmp;

	max->error = 1;
	if (!(node = list_error_new(str)))
		return ;
	if (*begin == NULL)
	{
		(*begin) = node;
		return ;
	}
	if (is_begin(begin, node))
		return ;
	tmp = (*begin);
	while (tmp->next != NULL)
	{
		if (ft_strcmp(node->name, tmp->next->name) <= 0)
		{
			node->next = tmp->next;
			tmp->next = node;
			return ;
		}
		tmp = tmp->next;
	}
	tmp->next = node;
}
