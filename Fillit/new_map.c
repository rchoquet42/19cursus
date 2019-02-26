/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 18:08:54 by rchoquet          #+#    #+#             */
/*   Updated: 2018/06/29 12:00:32 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		sizeof_map(int count)
{
	int	res;

	res = count * 4;
	return (ft_sqrt(res));
}

int		ft_sqrt(int nbr)
{
	int i;

	i = 1;
	while (i * i < nbr)
		i++;
	return (i);
}

char	*new_map(int nbr)
{
	int		i;
	char	*res;

	i = 0;
	if (!(res = (char*)malloc(sizeof(char) * (nbr * nbr) + 1)))
		return (NULL);
	while (i < nbr * nbr)
		res[i++] = '.';
	res[i] = '\0';
	return (res);
}
