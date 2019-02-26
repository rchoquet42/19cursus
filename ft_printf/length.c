/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:26:46 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/25 17:20:40 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_length(const char **format, t_options *opt)
{
	int		i;
	char	*tmp;

	i = 0;
	if (is_length(*(format)[i]) == -1)
		return ;
	while ((*format)[i] != '\0' && is_length((*format)[i]) != -1)
		i++;
	tmp = ft_strsub(*format, 0, i);
	if (!ft_strcmp(tmp, "hh"))
		opt->length = ft_strdup("hh");
	else if (!ft_strcmp(tmp, "h"))
		opt->length = ft_strdup("h");
	else if (!ft_strcmp(tmp, "l"))
		opt->length = ft_strdup("l");
	else if (!ft_strcmp(tmp, "ll"))
		opt->length = ft_strdup("ll");
	else if (!ft_strcmp(tmp, "j"))
		opt->length = ft_strdup("j");
	else if (!ft_strcmp(tmp, "z"))
		opt->length = ft_strdup("z");
	(*format) += ((*format)[i] == '\0' ? 0 : i);
}

static int	is_length(char c)
{
	int		i;

	i = 0;
	while (LENGTH[i])
	{
		if (c == LENGTH[i])
			return (i);
		i++;
	}
	return (-1);
}
