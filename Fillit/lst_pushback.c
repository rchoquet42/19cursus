/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_pushback.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 17:09:37 by dazheng           #+#    #+#             */
/*   Updated: 2018/06/29 14:45:18 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

t_block	*lst_create(short **coord)
{
	t_block	*new;

	if (!(new = (t_block*)malloc(sizeof(t_block))))
		return (NULL);
	new->block = coord;
	new->next = NULL;
	return (new);
}

void	lst_pushback(t_block **begin, short **coord)
{
	char	count;
	t_block	*save;

	count = 'A';
	save = *begin;
	if (*begin == NULL)
	{
		*begin = lst_create(coord);
		(*begin)->letter = count;
	}
	else
	{
		while (save->next)
		{
			save = save->next;
			count++;
		}
		save->next = lst_create(coord);
		save->next->letter = count + 1;
	}
}

void	lst_free(t_block **begin)
{
	t_block	*tmp;
	int		x;

	x = 0;
	if (*begin == NULL)
		return ;
	while (*begin)
	{
		tmp = (*begin)->next;
		while (x < 4)
		{
			free(((*begin)->block)[x]);
			x++;
		}
		free((*begin)->block);
		free(*begin);
		*begin = tmp;
	}
}
