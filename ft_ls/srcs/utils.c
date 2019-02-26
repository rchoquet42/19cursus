/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 01:31:11 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/08 14:16:40 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_max(t_max *max)
{
	ft_bzero(max, sizeof(t_max));
	/*max->total = 0;
	max->len_u = 0;
	max->len_g = 0;
	max->len_l = 0;
	max->len_s = 0;
	max->len_n = 0;
	max->device = 0;
	max->nb_node = 0;
	max->error = 0;
	max->dir = 0;
	max->device = 0;*/
}

void	update_max(t_max *max, t_info *info)
{
	int	len;

	len = ft_strlen(info->name);
	max->nb_node += 1;
	max->total += info->block;
	max->len_u = (max->len_u < info->len_uid ? info->len_uid : max->len_u);
	max->len_g = (max->len_g < info->len_gruid ? info->len_gruid : max->len_g);
	max->len_l = (max->len_l < info->len_link ? info->len_link : max->len_l);
	max->len_s = (max->len_s < info->len_size ? info->len_size : max->len_s);
	max->len_n = (max->len_n < len ? len : max->len_n);
	if (max->device == 0)
		max->device = ((info->type == 'c') || (info->type == 'b') ? 1 : 0);
}

void	fts_open_error(t_info **begin, t_info **end)
{
	free_list(begin, end);
	perror("ls: fts_open");
	exit(1);
}

t_util	*new_util(t_info **begin, t_info **end, int i)
{
	t_util	*ut;

	if (!(ut = (t_util*)malloc(sizeof(t_util))))
		return (NULL);
	ut->begin = begin;
	ut->end = end;
	ut->i = i;
	return (ut);
}

void	fill_stat(struct stat file_stat, t_info *info, char *path)
{
	info->right = ft_right(&file_stat, info);
	info->uid = ft_uid(&file_stat);
	info->gruid = ft_gruid(&file_stat);
	info->month = ft_month(&file_stat);
	info->day = ft_day(&file_stat);
	info->hour = ft_hour(&file_stat);
	info->link = file_stat.st_nlink;
	info->size = file_stat.st_size;
	info->block = file_stat.st_blocks;
	info->len_uid = ft_strlen(info->uid);
	info->len_gruid = ft_strlen(info->gruid);
	info->len_size = size_nbr(10, info->size);
	info->len_link = size_nbr(10, info->link);
	if ((info->type == 'b') || info->type == 'c')
	{
		info->major = (major(file_stat.st_rdev));
		info->minor = (minor(file_stat.st_rdev));
	}
	else if (info->type != 'b' && info->type != 'c')
		get_acl_attr(info, path);
	if (info->type == 'l')
		info->name_lnk = ft_name_lnk(&file_stat, path);
}
