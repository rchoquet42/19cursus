/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 12:38:52 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:16:39 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned long	i;
	char			*cb;

	cb = (char*)b;
	i = 0;
	while (i < len)
	{
		cb[i] = (char)c;
		i++;
	}
	return (b);
}
