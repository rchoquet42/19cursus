/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 10:28:09 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/24 19:19:08 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**⛹⛹⛹⛹⛹⛹⛹⛹⛹⛹⛹    ⛹             ⛪⛪⛪⛪⛪⛪⛪⛪⛪⛪⛪⛪⛪⛪⛪      ⛪   ⛪   ⛷ ⛷     ⛷⛷   ⛷
*/

static int	size_nbr2(unsigned long long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 2;
		i++;
	}
	return (i);
}

static void	ft_write2(wint_t c)
{
	char t;

	t = (c >> 6) | 0xC0;
	write(1, &t, 1);
	t = ((0x3F & c) | 0x80);
	write(1, &t, 1);
}

static void	ft_write3(wint_t c)
{
	char t;

	t = (c >> 12) | 0xE0;
	write(1, &t, 1);
	t = (((c >> 6) & 0x3F) | 0x80);
	write(1, &t, 1);
	t = ((0x3F & c) | 0x80);
	write(1, &t, 1);
}

static void	ft_write4(wint_t c)
{
	char t;

	t = (c >> 18) | 0xF0;
	write(1, &t, 1);
	t = (((c >> 12) & 0x3F) | 0x80);
	write(1, &t, 1);
	t = (((c >> 6) & 0x3F) | 0x80);
	write(1, &t, 1);
	t = ((0x3F & c) | 0x80);
	write(1, &t, 1);
}

void		ft_putwchar(wint_t c)
{
	int		len;

	len = size_nbr2(c);
	if (len <= 7)
		ft_putchar(c);
	else if (len > 7 && len <= 11)
		ft_write2(c);
	else if (len > 11 && len <= 16)
		ft_write3(c);
	else if (len > 16 && len <= 21)
		ft_write4(c);
}
