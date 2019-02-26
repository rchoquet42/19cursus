/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strichar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 12:02:08 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:20:11 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t	ft_strichar(const char *str, int c)
{
	unsigned long	i;
	unsigned long	len;

	i = 0;
	len = ft_strlen(str);
	while (i < ft_strlen(str))
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}
	return (-1);
}
