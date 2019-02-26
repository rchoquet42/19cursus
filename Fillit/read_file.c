/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:25:36 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/29 14:46:44 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	read_file(char **argv, t_block **begin)
{
	int		fd;
	int		ret;
	char	buf[21];
	int		count;

	count = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (error(begin));
	while ((ret = read(fd, buf, 21)))
	{
		count++;
		buf[ret] = '\0';
		if (is_valid(buf, ret))
			lst_pushback(begin, to_coord(buf));
		else
			return (error(begin));
	}
	if (buf[19] != '\n' || buf[20] != '\0' || count > 26)
		return (error(begin));
	if (close(fd) == -1)
		return (error(begin));
	return (count);
}
