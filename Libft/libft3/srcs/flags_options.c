/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 20:52:06 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:13:37 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

/*
** Applique le flag #
*/

void	hashtag(t_options *opt)
{
	char	*save;
	int		cmp;

	cmp = ft_strcmp(opt->to_printf, "0");
	if ((opt->conversion == LO || opt->conversion == UO)
	&& (cmp != 0))
	{
		if (opt->to_printf[0] != '0')
		{
			save = opt->to_printf;
			opt->to_printf = ft_strjoin("0", opt->to_printf);
			free(save);
		}
	}
	else if ((opt->conversion == LX || opt->conversion == UX)
	&& (cmp != 0))
	{
		save = opt->to_printf;
		if (opt->conversion == LX)
			opt->to_printf = ft_strjoin("0x", opt->to_printf);
		else
			opt->to_printf = ft_strjoin("0X", opt->to_printf);
		free(save);
	}
}

/*
** Applique le flag +
*/

void	add(t_options *opt)
{
	char *save;

	if (opt->to_printf[0] != '-')
	{
		save = opt->to_printf;
		opt->to_printf = ft_strjoin("+", opt->to_printf);
		free(save);
	}
}

/*
** Applique le flag ' '
*/

void	space(t_options *opt)
{
	char *save;

	if (opt->to_printf[0] != '-')
	{
		save = opt->to_printf;
		opt->to_printf = ft_strjoin(" ", opt->to_printf);
		free(save);
	}
}
