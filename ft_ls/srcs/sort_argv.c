/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_argv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/13 20:01:34 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/29 18:59:55 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char	**lst_to_tab(t_info **begin, t_info **end, int len, int opt)
{
	char		**files;
	t_info		*tmp;
	t_info		*save;
	int			a;

	a = 0;
	if ((*begin) == NULL)
		return (NULL);
	if (!(files = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	files[len] = NULL;
	tmp = ((g_options & OPT_LR) == 0 ? (*begin) : (*end));
	while (tmp)
	{
		files[a++] = ft_strdup(tmp->name);
		save = ((g_options & OPT_LR) == 0 ? tmp->next : tmp->prev);
		free_node(begin, end, tmp);
		tmp = save;
	}
	return (files);
}

char		**sort_dirs(char **argv, int i)
{
	t_info		*begin;
	t_info		*end;
	t_info		*info;
	int			len;

	set_node_to_null(&begin, &end);
	len = 0;
	while (argv[i])
	{
		info = list_new();
		if (get_stat(info, argv[i]) == 0)
			free_inside(info);
		else if (info->type == 'd')
		{
			list_add(info, &begin, &end);
			len++;
		}
		else
			free_inside(info);
		i++;
	}
	return (lst_to_tab(&begin, &end, len, 1));
}

void		sort_files(char **argv, t_util *ut, t_max *max)
{
	t_info		*info;
	t_error		*begin_er;

	begin_er = NULL;
	while (argv[ut->i])
	{
		info = list_new();
		if (get_stat(info, argv[ut->i]) == 0)
		{
			free_inside(info);
			if (argv[ut->i][0] == '\0')
				fts_open_error(ut->begin, ut->end);
			else
				lst_error(argv[ut->i], &begin_er, max);
		}
		else if (info->type != 'd')
		{
			list_add(info, ut->begin, ut->end);
			update_max(max, info);
		}
		else
			free_inside(info);
		(ut->i)++;
	}
	display_error(begin_er);
}
