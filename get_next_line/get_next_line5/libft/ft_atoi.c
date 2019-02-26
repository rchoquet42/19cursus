/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 23:50:46 by rchoquet          #+#    #+#             */
/*   Updated: 2018/06/19 20:46:52 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int				sign;
	unsigned long	res;

	res = 0;
	sign = 1;
	while (*str == '\t' || *str == '\v' || *str == '\f' || *str == '\r'
	|| *str == '\n' || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		sign = (*str - 44) * -1;
		str++;
	}
	while (*str)
	{
		if (res > 9223372036854775807)
			return (sign > 0 ? -1 : 0);
		if (*str < '0' || *str > '9')
			return ((int)res * sign);
		res = (res * 10) + (*str - '0');
		str++;
	}
	if (res > 9223372036854775807)
		return (sign > 0 ? -1 : 0);
	return ((int)res * sign);
}
