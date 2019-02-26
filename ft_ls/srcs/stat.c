/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/04 23:31:53 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/30 17:32:46 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		get_stat(t_info *info, char *file)
{
	struct stat	file_stat;
	char		*path;

	path = ft_strjoin(info->path, file);
	if (((g_options & OPT_LL) || (g_options & OPT_LT) ? lstat(path, &file_stat)
	: stat(path, &file_stat)) < 0)
	{
		if (lstat(path, &file_stat) < 0)
		{
			free(path);
			return (0);
		}
	}
	info->type = ft_type(&file_stat);
	info->name = ft_strdup(file);
	info->inode = file_stat.st_ino;
	if (g_options & OPT_LT)
		info->time = ft_time(&file_stat);
	if (g_options & OPT_US)
		info->size = file_stat.st_size;
	if ((g_options & OPT_LL) || (g_options & OPT_LG))
		fill_stat(file_stat, info, path);
	free(path);
	return (1);
}

void	get_acl_attr(t_info *info, char *path)
{
	acl_t		acl;
	int			temp;
	char		*buf;

	buf = NULL;
	if ((acl = acl_get_file(path, ACL_TYPE_EXTENDED)) != (acl_t)NULL)
	{
		info->acl_c = '+';
		acl_free((void*)acl);
	}
	if ((temp = listxattr(path, NULL, 0, XATTR_NOFOLLOW)) > 0)
	{
		info->acl_c = '@';
		if (g_options & OPT_ATTR)
		{
			if (!(buf = (char*)malloc(sizeof(char) * temp)))
				return ;
			if (listxattr(path, buf, temp, XATTR_NOFOLLOW) <= 0)
				return ;
			info->acl_list = buf;
			info->acl_len = temp;
		}
	}
}

char	*ft_name_lnk(struct stat *st, char *path)
{
	char	*path_lnk;
	int		tmp;

	if (st->st_size == 0)
		st->st_size = PATH_MAX;
	if (!(path_lnk = (char*)malloc((st->st_size + 1) * sizeof(char))))
		return (NULL);
	if ((tmp = readlink(path, path_lnk, st->st_size)) == -1)
	{
		perror("");
		free(path_lnk);
		return (ft_strdup("(null)"));
	}
	path_lnk[tmp] = '\0';
	return (path_lnk);
}

char	*ft_uid(struct stat *st)
{
	struct passwd *psw;

	if ((psw = getpwuid(st->st_uid)) == NULL)
		return (itoa_base(10, st->st_uid));
	return (ft_strdup(psw->pw_name));
}

char	*ft_gruid(struct stat *st)
{
	struct group *grp;

	if ((grp = getgrgid(st->st_gid)) == NULL)
		return (itoa_base(10, st->st_gid));
	return (ft_strdup(grp->gr_name));
}
