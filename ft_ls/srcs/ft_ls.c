/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/09 16:20:31 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/29 20:43:23 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_ls(char **dir, t_info **begin, t_info **end, t_max *max)
{
	int		i;
	int		len;

	len = (max->error == 1 ? 1 : 0);
	if (*begin != NULL)
	{
		len = 1;
		max->dir = 0;
		display_node(begin, end, 0, max);
		free_list(begin, end);
		((dir != NULL) ? ft_printf("\n") : 0);
	}
	i = 0;
	if (dir != NULL)
	{
		while (dir[i])
		{
			len += i;
			create_chain_list(dir[i], begin, end, (len != 0
			|| (dir[i + 1] != NULL) ? 1 : 0));
			set_node_to_null(begin, end);
			((dir[++i] != NULL) ? ft_printf("\n") : 0);
		}
	}
}

void	create_chain_list(char *dir_name, t_info **begin, t_info **end, int i)
{
	DIR				*dirp;
	char			*temp;
	t_util			ut;
	t_max			max;

	ut.begin = begin;
	ut.end = end;
	ut.dir_name = dir_name;
	ut.i = i;
	if ((dirp = opendir(dir_name)) == NULL)
	{
		if ((temp = ft_strrchr(dir_name, '/')) != NULL)
		{
			temp = ft_strsub(temp, 1, ft_strlen(temp) - 1);
			ft_printf("%s:\n", dir_name);
			ft_printf_fd(2, "ls: %s: ", temp);
			(temp != NULL ? free(temp) : 0);
		}
		else
			ft_printf_fd(2, "%s:\nls: %s: ", dir_name, dir_name);
		perror("");
		return ;
	}
	init_max(&max);
	ft_read_dir(dirp, &ut, &max);
}

void	ft_read_dir(DIR *dirp, t_util *ut, t_max *max)
{
	t_info			*info;
	struct dirent	*dp;

	while ((dp = readdir(dirp)) != NULL)
	{
		if ((dp->d_name[0] == '.' && ((g_options & OPT_LA) == 0)))
			continue ;
		if (!(info = list_new()))
			continue ;
		free(info->path);
		if (!(info->path = ft_strjoin(ut->dir_name, "/"))
		&& free_node_alone(info))
			continue ;
		if (get_stat(info, dp->d_name) == 0)
		{
			ft_printf_fd(2, "ls: %s: %s\n", dp->d_name, strerror(errno));
			free_node_alone(info);
			continue ;
		}
		list_add(info, ut->begin, ut->end);
		update_max(max, info);
	}
	closedir(dirp);
	ft_recursive(ut, max);
}

void	ft_recursive(t_util *ut, t_max *max)
{
	t_info			*info;

	if (*(ut->begin) == NULL && (ut->i != 0))
	{
		ft_printf("%s:\n", ut->dir_name);
		return ;
	}
	max->dir = 1;
	display_node(ut->begin, ut->end, ut->i, max);
	((g_options & OPT_UR) == 0 ? free_list(ut->begin, ut->end)
	: free_lst_not_dir(ut->begin, ut->end));
	info = ((g_options & OPT_LR) != 0 ? *(ut->end) : *(ut->begin));
	if (info != NULL && (g_options & OPT_UR))
		ft_subdir(info, ut);
}

void	ft_subdir(t_info *info, t_util *ut)
{
	char	*temp;
	t_info	*save;

	while (info)
	{
		if (info->type == 'd' && (ft_strcmp(info->name, ".") == 0
		|| ft_strcmp(info->name, "..") == 0))
		{
			free_node(ut->begin, ut->end, info);
			info = ((g_options & OPT_LR) != 0 ? info->prev : info->next);
			continue ;
		}
		ft_printf("\n");
		save = ((g_options & OPT_LR) != 0 ? info->prev : info->next);
		if (!(temp = ft_strjoin(info->path, info->name)))
		{
			free_node(ut->begin, ut->end, info);
			continue ;
		}
		(ut->i)++;
		create_chain_list(temp, &(info->sub_begin), &(info->sub_end), ut->i);
		free_node(ut->begin, ut->end, info);
		free(temp);
		info = save;
	}
}
