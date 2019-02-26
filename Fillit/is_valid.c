/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:08:24 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/29 12:00:58 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		is_valid(char *buf, int ret)
{
	t_valid	info;
	t_valid	*ptr;
	int		pos;

	pos = 0;
	info = init_info();
	ptr = &info;
	if (ret < 20 || (ret == 21 && buf[20] != '\n'))
		return (0);
	while (buf[pos] && pos < 20)
	{
		if (buf[pos] == '#')
			valid_side(pos, buf, ptr);
		valid_char(buf[pos], ptr);
		if ((pos + 1) % 5 == 0 && buf[pos] != '\n')
			return (0);
		pos++;
	}
	if (info.nb_space == 12 && info.nb_block == 4 && info.line == 1 &&
		info.side > 5)
		return (1);
	return (0);
}

void	valid_side(int pos, char *buf, t_valid *ptr)
{
	int count;

	count = 0;
	if ((pos + 2) % 5 != 0 && buf[pos + 1] == '#')
		count++;
	if (pos != 0 && (pos % 5) != 0 && buf[pos - 1] == '#')
		count++;
	if (pos < 15 && buf[pos + 5] == '#')
		count++;
	if (pos > 4 && buf[pos - 5] == '#')
		count++;
	ptr->side += count;
}

t_valid	init_info(void)
{
	t_valid info;

	info.nb_block = 0;
	info.nb_space = 0;
	info.line = 1;
	info.side = 0;
	return (info);
}

void	valid_char(char c, t_valid *ptr)
{
	if (c == '#')
		ptr->nb_block += 1;
	else if (c == '.')
		ptr->nb_space += 1;
	return ;
}
