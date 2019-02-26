/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ludecimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:49:40 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:28:27 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	size_n10(unsigned long int nbr)
{
	int i;

	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		i++;
		nbr /= 10;
	}
	return (i);
}

void		printf_ludecimal(t_options *opt, va_list ap)
{
	unsigned long int	nbr;
	char				*str;
	int					len;
	char				*tmp;

	nbr = va_arg(ap, unsigned long int);
	len = size_n10(nbr);
	if (!(str = (char*)malloc(sizeof(char) * len + 1)))
		return ;
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	tmp = opt->to_printf;
	opt->to_printf = str;
	free(tmp);
}
