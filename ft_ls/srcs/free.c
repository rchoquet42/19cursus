/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/14 16:22:18 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/29 18:41:20 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void		free_list(t_info **begin, t_info **end)
{
	t_info	*tmp;
	t_info	*save;

	if (*begin == NULL)
		return ;
	tmp = (*begin);
	while (tmp)
	{
		save = tmp->next;
		free_inside(tmp);
		tmp = save;
	}
	*begin = NULL;
	*end = NULL;
}

void		free_inside(t_info *tmp)
{
	(tmp->path != NULL ? free(tmp->path) : 0);
	(tmp->name != NULL ? free(tmp->name) : 0);
	if (((g_options & OPT_LL) || (g_options & OPT_LG)) != 0)
	{
		(tmp->right != NULL ? free(tmp->right) : 0);
		(tmp->gruid != NULL ? free(tmp->gruid) : 0);
		(tmp->uid != NULL ? free(tmp->uid) : 0);
		(tmp->month != NULL ? free(tmp->month) : 0);
		(tmp->day != NULL ? free(tmp->day) : 0);
		(tmp->hour != NULL ? free(tmp->hour) : 0);
		if (tmp->type == 'l')
			(tmp->name_lnk != NULL ? free(tmp->name_lnk) : 0);
	}
	free(tmp);
}

void		free_lst_not_dir(t_info **begin, t_info **end)
{
	t_info	*tmp;
	t_info	*save_next;

	tmp = (*begin);
	while (tmp)
	{
		save_next = tmp->next;
		if (tmp->type != 'd')
		{
			if ((*end) == (*begin))
				set_node_to_null(begin, end);
			else if (!(update_head_tail(tmp, begin, end)))
				unlink_node(tmp);
			free_inside(tmp);
		}
		tmp = save_next;
	}
}

void		free_node(t_info **begin, t_info **end, t_info *node)
{
	if ((*begin) == NULL)
		return ;
	if ((*begin) == (*end))
	{
		(*begin) = NULL;
		(*end) = NULL;
	}
	else if ((*begin) == node)
	{
		(*begin) = (*begin)->next;
		(*begin)->prev = NULL;
	}
	else if ((*end) == node)
	{
		(*end) = (*end)->prev;
		(*end)->next = NULL;
	}
	else
		unlink_node(node);
	free_inside(node);
}
