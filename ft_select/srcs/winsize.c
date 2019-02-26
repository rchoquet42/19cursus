/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   winsize.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 12:15:08 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/26 17:23:09 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

bool	change_winsize(void)
{
	struct winsize	sz;
	int				col;
	int				line;
	static int		st_col = 0;
	static int		st_line = 0;

	ioctl(0, TIOCGWINSZ, &sz);
	col = sz.ws_col;
	line = sz.ws_row;
	if (col == st_col && line == st_line)
		return (FALSE);
	st_col = col;
	st_line = line;
	return (TRUE);
}

bool	check_winsize(t_maxinfo *max)
{
	struct winsize	sz;
	size_t			col;
	size_t			line;
	size_t			tmp;
	size_t			i;

	i = 1;
	tmp = max->elem;
	ioctl(0, TIOCGWINSZ, &sz);
	col = sz.ws_col;
	line = sz.ws_row;
	max->line = line;
	if (tmp <= line && max->max_len > col)
		return (FALSE);
	while (tmp >= line && i++ && (tmp -= line))
		if (tmp <= line)
		{
			if (col > (max->startcol = (max->max_len % 8 == 0
			? i * (max->max_len + 8)
			: i * (max->max_len + (8 - (max->max_len % 8))))))
				if ((max->col = i) && (max->startcol /= i))
					return (TRUE);
			return (FALSE);
		}
	return (TRUE);
}
