/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 12:42:49 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:13:19 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		check_flags(const char **format, t_options *opt)
{
	int i;

	i = 0;
	while (i < 5)
	{
		opt->flags[i] = 0;
		i++;
	}
	while ((i = is_flag((**format), opt)) != -1)
	{
		opt->flags[i] = 1;
		(*format)++;
	}
}

/*
** Verifie si un caractere est un flag ger(alt + 144)
*/

static int	is_flag(char c, t_options *opt)
{
	int	i;

	i = 0;
	while (FLAGS[i])
	{
		if (c == FLAGS[i])
			return (i);
		i++;
	}
	return (-1);
}

/*
** Gere la priorite des flags
*/

void		flags_overrides(t_options *opt)
{
	if (opt->flags[FZ] == 1 && opt->precision >= 0 &&
	(opt->conversion > US && opt->conversion < LC))
		opt->flags[FZ] = 0;
	if (opt->flags[FZ] == 1 && opt->flags[FL] == 1)
		opt->flags[FZ] = 0;
	if (opt->flags[FZ] == 1 && opt->flags[FL] == 0)
		opt->blank = '0';
	if (opt->flags[FSP] == 1 && opt->flags[FP] == 1)
		opt->flags[FSP] = 0;
	if (opt->flags[FSP] == 1 && opt->flags[FZ] == 1)
		opt->width -= 1;
}

/*
** Applique les flags + et ' '
*/

void		apply_add_space(t_options *opt)
{
	if (opt->conversion >= UD && opt->conversion <= I)
	{
		if (opt->flags[FP] == 1)
			add(opt);
		else if (opt->flags[FSP] == 1)
			space(opt);
	}
}
