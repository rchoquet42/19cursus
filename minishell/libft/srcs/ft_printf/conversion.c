/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 18:09:52 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/24 17:49:06 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_conversion(const char **format, t_options *opt)
{
	int ret;

	if ((ret = is_conversion(**format, opt)) != -1)
		opt->conversion = ret;
	else
	{
		opt->conversion = 16;
		free(opt->to_printf);
		opt->to_printf = ft_strnew(1);
		opt->to_printf[0] = **format;
		opt->to_printf[1] = '\0';
	}
}

/*
** conv = toutes les convertions prises en compte
*/

int		is_conversion(char c, t_options *opt)
{
	char	*conv;
	int		i;

	i = 0;
	conv = CONV;
	while (conv[i])
	{
		if (conv[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
