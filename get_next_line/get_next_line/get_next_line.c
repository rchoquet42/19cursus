/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/28 15:30:15 by rchoquet          #+#    #+#             */
/*   Updated: 2018/07/08 23:24:41 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	int				ret;
	char			buf[BUFF_SIZE + 1];
	t_block			*temp;
	static t_block	*begin = NULL;
	char			*save;

	if (fd < 0 || line == NULL)
		return (-1);
	begin = (begin == NULL ? find_fd(begin, fd) : begin);
	temp = find_fd(begin, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		if (ret == -1)
			return (-1);
		buf[ret] = 0;
		save = ft_swiss(&temp, ret, line, 0);
		temp->str = ft_strjoin(save, buf);
		free(save);
		if ((ret = ft_strichar(temp->str, '\n')) != -1)
		{
			ft_swiss(&temp, ret, line, 1);
			return (*(temp->str) == '\0' ? ft_lst_freenode(fd, &begin) : 1);
		}
	}
	return ((ft_strcmp(temp->str, "") ? ft_read_eof(&temp, line, &begin) : 0));
}

char	*ft_swiss(t_block **temp, int ret, char **line, int option)
{
	char	*save;

	if (option == 0)
	{
		save = ft_strdup((*temp)->str);
		free((*temp)->str -= (*temp)->count);
		(*temp)->count = 0;
		return (save);
	}
	else if (option == 1)
	{
		*line = ft_strsub((*temp)->str, 0, ret);
		(*temp)->str += (ret + 1);
		(*temp)->count += (ret + 1);
		return (NULL);
	}
	return (NULL);
}

int		ft_lst_freenode(int fd, t_block **begin)
{
	t_block *save;
	t_block *temp;
	int		count;

	if ((*begin)->fd == fd)
	{
		save = (*begin)->next;
		count = (*begin)->count;
		((*begin)->str) -= count;
		free((*begin)->str);
		free((*begin));
		(*begin) = save;
		return (1);
	}
	temp = (*begin);
	while (temp->next != NULL && temp->next->fd != fd)
		temp = temp->next;
	save = temp->next;
	free(save->str -= save->count);
	temp->next = save->next;
	free(save);
	return (1);
}

int		ft_read_eof(t_block **temp, char **line, t_block **begin)
{
	int				i;
	unsigned long	len;

	i = ft_strichar((*temp)->str, '\n');
	if (i == -1)
	{
		*line = ft_strdup((*temp)->str);
		len = ft_strlen((*temp)->str);
		(*temp)->str += len;
		(*temp)->count += len;
		return (ft_lst_freenode((*temp)->fd, begin));
	}
	*line = ft_strsub((*temp)->str, 0, i);
	(*temp)->str += (i + 1);
	(*temp)->count += (i + 1);
	if (ft_strlen((*temp)->str) == 0)
		return (ft_lst_freenode((*temp)->fd, begin));
	return (1);
}

t_block	*find_fd(t_block *begin, int fd)
{
	t_block *temp;
	t_block *save;

	save = NULL;
	temp = begin;
	while (temp != NULL)
	{
		if (temp->fd == fd)
			return (temp);
		save = temp;
		temp = temp->next;
	}
	if (!(temp = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	if (!(temp->str = ft_strdup("")))
		return (NULL);
	temp->fd = fd;
	temp->count = 0;
	temp->next = NULL;
	if (save != NULL)
		save->next = temp;
	return (temp);
}
