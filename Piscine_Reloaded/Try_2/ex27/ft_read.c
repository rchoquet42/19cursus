/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:39:21 by rchoquet          #+#    #+#             */
/*   Updated: 2018/06/12 15:16:09 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

void	ft_display_file(char *file)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		ret;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		write(2, "open() failed.\n", 15);
		return ;
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		write(1, buf, ret);
	}
	if (close(fd) == -1)
	{
		write(2, "close() failed.\n", 16);
		return ;
	}
}
