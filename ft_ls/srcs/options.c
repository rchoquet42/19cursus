/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:32:25 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/29 16:31:06 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		override_opt(void)
{
	if (g_options & OPT_US)
		g_options &= ~OPT_LT;
}

static int		is_options(char opt)
{
	int i;

	i = 0;
	while (FLAG[i])
	{
		if (FLAG[i] == opt)
			return (1);
		i++;
	}
	return (-1);
}

static void		add_options(char *opt)
{
	if (*opt == 'a')
		g_options |= OPT_LA;
	else if (*opt == 'r')
		g_options |= OPT_LR;
	else if (*opt == 't')
		g_options |= OPT_LT;
	else if (*opt == 'R')
		g_options |= OPT_UR;
	else if (*opt == 'u')
		g_options |= OPT_LU;
	else if (*opt == 'g')
		g_options |= OPT_LG;
	else if (*opt == 'l' && ((g_options & OPT_LG) == 0))
		g_options |= OPT_LL;
	else if (*opt == '@')
		g_options |= OPT_ATTR;
	else if (*opt == 'S')
		g_options |= OPT_US;
	else if (*opt == 'x')
	{
		g_options |= OPT_LX;
		g_options &= ~OPT_LL;
		g_options &= ~OPT_LG;
	}
}

int				check_options(char *opt)
{
	if (*opt != '-' || (ft_strcmp("-", opt) == 0))
		return (0);
	else
	{
		opt++;
		while (*opt)
		{
			if (*opt == '-' && *(opt + 1) == '\0')
				return (1);
			if (is_options(*opt) == -1
			|| (*opt == '-' && *(opt + 1) != '\0'))
			{
				ft_usage(*opt);
				exit(1);
			}
			add_options(opt);
			opt++;
		}
	}
	override_opt();
	return (1);
}
