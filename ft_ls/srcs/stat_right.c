/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stat_right.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 20:56:33 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/12 17:00:51 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	ft_type(struct stat *st)
{
	mode_t		mode;

	mode = (st->st_mode);
	if (S_ISFIFO(mode))
		return ('p');
	if (S_ISCHR(mode))
		return ('c');
	if (S_ISDIR(mode))
		return ('d');
	if (S_ISBLK(mode))
		return ('b');
	if (S_ISREG(mode))
		return ('-');
	if (S_ISLNK(mode))
		return ('l');
	if (S_ISSOCK(mode))
		return ('s');
	return (0);
}

char	*ft_right(struct stat *st, t_info *info)
{
	char	*res;
	int		mode;

	mode = st->st_mode;
	if (!(res = (char*)malloc(sizeof(char) * 11)))
		return (NULL);
	res[10] = '\0';
	res[0] = info->type;
	res[1] = (mode & S_IRUSR ? 'r' : '-');
	res[2] = (mode & S_IWUSR ? 'w' : '-');
	res[3] = ft_exec_owner(mode);
	res[4] = (mode & S_IRGRP ? 'r' : '-');
	res[5] = (mode & S_IWGRP ? 'w' : '-');
	res[6] = ft_exec_group(mode);
	res[7] = (mode & S_IROTH ? 'r' : '-');
	res[8] = (mode & S_IWOTH ? 'w' : '-');
	res[9] = ft_exec_other(mode);
	return (res);
}

char	ft_exec_other(int mode)
{
	if ((mode & S_ISVTX))
	{
		if (mode & S_IXOTH)
			return ('t');
		else
			return ('T');
	}
	else
	{
		if (mode & S_IXOTH)
			return ('x');
		else
			return ('-');
	}
}

char	ft_exec_owner(int mode)
{
	if (!(mode & S_IXUSR))
	{
		if (mode & S_ISUID)
			return ('S');
		else
			return ('-');
	}
	else
	{
		if (mode & S_ISUID)
			return ('s');
		else
			return ('x');
	}
}

char	ft_exec_group(int mode)
{
	if (!(mode & S_IXGRP))
	{
		if (mode & S_ISGID)
			return ('S');
		else
			return ('-');
	}
	else
	{
		if (mode & S_ISGID)
			return ('s');
		else
			return ('x');
	}
}
