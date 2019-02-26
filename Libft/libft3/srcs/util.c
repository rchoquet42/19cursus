/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/23 18:22:32 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:29:37 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** I m so sorry...
*/

void	swiss(t_options *opt, int c)
{
	char	*save;

	if (c == 0)
	{
		if ((opt->conversion == LS && ft_strcmp(opt->length, "l") != 0)
		|| (!ft_strcmp(opt->to_printf, "(null)")))
		{
			save = opt->to_printf;
			opt->to_printf = ft_strsub(opt->to_printf, 0, opt->precision);
			free(save);
		}
	}
	else if (c == 19)
	{
		save = opt->to_printf;
		opt->to_printf = ft_strdup("");
		free(save);
	}
	else if (c == 42)
	{
		free(opt->to_printf);
		opt->to_printf = ft_strdup("0x");
	}
}
