/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_coord.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 15:27:10 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/29 12:01:09 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

short	**to_coord(char *tetris)
{
	short	**tab;
	int		i;
	int		x;

	i = -1;
	x = 0;
	if (!(tab = (short**)malloc(sizeof(short*) * 4)))
		return (NULL);
	while (tetris[++i])
	{
		if (tetris[i] == '#')
		{
			if (!(tab[x] = (short*)malloc(sizeof(short) * 2)))
				return (NULL);
			if (x == 0)
				set_x_0(i, tab);
			else
				set_x(i, x, tab);
			x++;
		}
	}
	return (tab);
}

void	set_x_0(int i, short **tab)
{
	tab[0][0] = (i / 5);
	tab[0][1] = (i % 5);
}

void	set_x(int i, int x, short **tab)
{
	tab[x][0] = (i / 5) - tab[0][0];
	tab[x][1] = (i % 5) - tab[0][1];
}
