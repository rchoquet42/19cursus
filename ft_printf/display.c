/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:34:37 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/30 17:47:01 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	display(t_options *opt)
{
	int		i;
	char	c;

	c = 0;
	i = ft_strlen(opt->to_printf);
	if ((opt->conversion == LC || opt->conversion == UC) && opt->c_char == 0)
	{
		i++;
		if (opt->width > 0)
		{
			if (opt->flags[FL] == 0)
				ft_putstr(opt->to_printf);
			write(1, &c, 1);
			if (opt->flags[FL] == 1)
				ft_putstr(opt->to_printf);
			return (i);
		}
		else
			write(1, &c, 1);
	}
	ft_putstr(opt->to_printf);
	return (i);
}
