/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 22:58:17 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:27:10 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			size_nbr(int base, unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		i++;
	}
	return (i);
}

char		*itoa_base(int base, long long nbr)
{
	char			*b;
	char			*res;
	int				len;
	int				sign;

	b = "0123456789abcdef";
	if (nbr == LONG_MIN)
		return ((res = ft_strdup("-9223372036854775808")));
	sign = (base == 10 && nbr < 0 ? 1 : 0);
	nbr = (sign == 1 ? nbr * -1 : nbr);
	len = size_nbr(base, nbr);
	len = (sign > 0 ? (len + 1) : len);
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len--] = '\0';
	while (len >= sign)
	{
		res[len--] = b[(nbr % base)];
		nbr /= base;
	}
	if (sign == 1)
		res[len] = '-';
	return (res);
}

char		*uitoa_base(int base, unsigned long long nbr)
{
	char	*b;
	char	*res;
	int		len;

	b = "0123456789abcdef";
	len = size_nbr(base, nbr);
	if (!(res = (char*)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len--] = b[(nbr % base)];
		nbr /= base;
	}
	return (res);
}
