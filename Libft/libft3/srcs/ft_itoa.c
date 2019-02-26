/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/19 11:38:28 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:14:38 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	sizeof_int(int n)
{
	int i;

	if (n == -2147483648)
		return (11);
	if ((i = (n < 0 ? 1 : 0)) > 0)
		n *= -1;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = sizeof_int(n);
	if (!(res = ft_strnew(len)))
		return (NULL);
	if (n == -2147483648)
	{
		res = ft_strdup("-2147483648");
		return (res);
	}
	if (n < 0)
	{
		res[i++] = '-';
		n *= -1;
	}
	len--;
	while (len >= i)
	{
		res[len--] = (n % 10) + 48;
		n /= 10;
	}
	return (res);
}
