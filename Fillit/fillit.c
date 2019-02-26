/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 10:05:46 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/10 18:00:57 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int		fillit(t_block *node, char *res)
{
	short	**block;
	int		x;
	int		len;
	char	*dst;
	int		pos;

	pos = 0;
	x = 0;
	block = node->block;
	len = ft_strlen(res);
	while (pos < len)
	{
		if (is_free(block, pos, res))
		{
			dst = fill_res(node, pos, res);
			if (node->next == NULL)
				return (1);
			if (fillit(node->next, dst))
				return (1);
			else
				unfill(res, pos, block);
		}
		pos++;
	}
	return (0);
}

void	unfill(char *res, int pos, short **block)
{
	int	i;
	int line;
	int	l;
	int	c;

	i = 1;
	res[pos] = '.';
	line = ft_sqrt(ft_strlen(res));
	l = pos / line;
	c = pos % line;
	while (i < 4)
	{
		res[((l + block[i][0]) * line) + (c + block[i][1])] = '.';
		i++;
	}
}

int		is_free(short **block, int pos, char *res)
{
	int i;
	int l;
	int c;
	int line;

	i = 1;
	line = ft_sqrt(ft_strlen(res));
	l = pos / line;
	c = pos % line;
	if ((ft_isalpha(res[pos])))
		return (0);
	while (i < 4)
	{
		if (l + block[i][0] >= line || c + block[i][1] >= line
		|| l + block[i][0] < 0 || c + block[i][1] < 0)
			return (0);
		if (ft_isalpha(res[((l + block[i][0]) * line) + (c + block[i][1])]))
			return (0);
		i++;
	}
	return (1);
}

char	*fill_res(t_block *node, int pos, char *res)
{
	int		i;
	int		l;
	int		c;
	int		line;
	short	**block;

	block = node->block;
	i = 1;
	line = ft_sqrt(ft_strlen(res));
	res[pos] = node->letter;
	l = pos / line;
	c = pos % line;
	while (i < 4)
	{
		res[((l + block[i][0]) * line) + (c + block[i][1])] = node->letter;
		i++;
	}
	return (res);
}
