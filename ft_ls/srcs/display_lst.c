/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/10 16:37:52 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/29 20:38:15 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_node(t_info **begin, t_info **end, int i, t_max *max)
{
	char	*save;

	if ((*begin) == NULL)
		return ;
	if (i != 0)
	{
		if (((*begin)->path)[0] == '/' && ((*begin)->path)[1] == '/')
			save = ft_strsub((*begin)->path, 1, ft_strlen((*begin)->path) - 2);
		else
			save = ft_strsub((*begin)->path, 0, ft_strlen((*begin)->path) - 1);
		ft_printf("%s:\n", save);
		(save != NULL ? free(save) : 0);
	}
	if ((g_options & OPT_LL) || (g_options & OPT_LG))
		display_lg(begin, end, max, max->dir);
	else if ((g_options & OPT_LX))
		display_basic(begin, end, max);
	else
		display_l1(begin, end);
}

void		display_l1(t_info **begin, t_info **end)
{
	t_info	*tmp;

	tmp = (g_options & OPT_LR ? (*end) : (*begin));
	while (tmp)
	{
		ft_printf("%s\n", tmp->name);
		tmp = (g_options & OPT_LR ? tmp->prev : tmp->next);
	}
}

void		display_lg(t_info **begin, t_info **end, t_max *max, int dir)
{
	t_info	*tmp;

	if (dir)
		ft_printf("total %d\n", max->total);
	tmp = (g_options & OPT_LR ? (*end) : (*begin));
	while (tmp)
	{
		display_l(tmp, max);
		if ((g_options & OPT_ATTR) && tmp->acl_c == '@')
			display_attr(tmp);
		tmp = (g_options & OPT_LR ? tmp->prev : tmp->next);
	}
}

void		display_l(t_info *tmp, t_max *max)
{
	int		len_u;
	int		len_g;
	int		len_l;
	int		len_s;

	len_u = max->len_u - tmp->len_uid;
	len_g = max->len_g - tmp->len_gruid;
	len_l = (max->len_l - tmp->len_link);
	len_s = max->len_s - tmp->len_size;
	ft_printf("%s%c", tmp->right, tmp->acl_c);
	while (len_l-- >= 0)
		ft_printf(" ");
	ft_printf("%hu", tmp->link);
	if ((g_options & OPT_LG) == 0)
	{
		ft_printf(" %s", tmp->uid);
		while (len_u-- >= 0)
			ft_printf(" ");
	}
	ft_printf(" %s", tmp->gruid);
	while (len_g-- >= 0)
		ft_printf(" ");
	while (len_s-- >= 0)
		ft_printf(" ");
	display_l_info(tmp, max);
}

void		display_attr(t_info *tmp)
{
	char	*save;
	int		i;
	int		len;
	int		size;
	int		space;

	i = 0;
	while (i < tmp->acl_len)
	{
		ft_printf("        %s", tmp->acl_list);
		len = ft_strlen(tmp->acl_list) + 1;
		save = ft_strjoin(tmp->path, tmp->name);
		if ((size = getxattr(save, tmp->acl_list,
		NULL, 0, 0, XATTR_NOFOLLOW)) < 0)
			return ;
		space = (28 - len) - size_nbr(10, size);
		while (space-- >= 0)
			ft_printf(" ");
		ft_printf("%d\n", size);
		ft_strdel(&save);
		tmp->acl_list += len;
		i += len;
	}
	tmp->acl_list -= i;
	free(tmp->acl_list);
}
