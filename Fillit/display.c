/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 21:19:54 by rchoquet          #+#    #+#             */
/*   Updated: 2018/06/29 11:59:06 by dazheng          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"

void	display(char *res, int size_map)
{
	int i;

	i = 0;
	while (res[i])
	{
		if ((i % size_map) == 0 && i != 0)
			ft_putchar('\n');
		ft_putchar(res[i]);
		i++;
	}
	ft_putchar('\n');
}
