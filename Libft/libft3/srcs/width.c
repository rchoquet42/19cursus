/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:49:41 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:29:55 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void		check_width(const char **format, t_options *opt)
{
	int		i;
	char	*temp_width;

	i = 0;
	while (ft_isdigit((*format)[i]))
		i++;
	temp_width = ft_strsub(*format, 0, i);
	opt->width = ft_atoi(temp_width);
	free(temp_width);
	(*format) += i;
}

static void	apply_width_for_less(t_options *opt, int blank)
{
	char	*temp;
	char	*save;
	char	*sub;
	int		len;

	if (opt->flags[FL] == 0)
	{
		blank += 1;
		if (!(temp = (char*)malloc(sizeof(char) * blank + 1)))
			return ;
		temp[blank--] = '\0';
		while (blank > 0)
			temp[blank--] = opt->blank;
		temp[blank] = '-';
		save = opt->to_printf;
		len = ft_strlen(opt->to_printf);
		sub = ft_strsub(opt->to_printf, 1, len);
		opt->to_printf = ft_strjoin(temp, sub);
		free(save);
		free(temp);
		free(sub);
	}
}

static void	apply_width_for_ptr(t_options *opt, int blank)
{
	char	*t;
	char	*save;
	char	*sub;

	if (!(t = (char*)malloc(sizeof(char) * blank + 1)))
		return ;
	t[blank--] = '\0';
	while (blank >= 0)
		t[blank--] = opt->blank;
	if (opt->flags[FL] == 0)
	{
		save = t;
		t = (opt->blank == '0' ? ft_strjoin("0x", t) : ft_strjoin(t, "0x"));
		free(save);
	}
	save = opt->to_printf;
	blank = ft_strlen(opt->to_printf);
	sub = ft_strsub(opt->to_printf, 2, blank);
	if (opt->flags[FL] == 0)
		opt->to_printf = ft_strjoin(t, sub);
	else if (opt->flags[FL] == 1)
		opt->to_printf = (ft_strjoin(opt->to_printf, t));
	free(save);
	free(sub);
	free(t);
}

static void	apply_width_for_c(t_options *opt, int blank)
{
	char	*tempo;
	char	*save;
	int		i;

	i = 0;
	if (!(tempo = (char*)malloc(sizeof(char) * (blank + 1))))
		return ;
	tempo[blank] = '\0';
	while (i < blank)
		tempo[i++] = opt->blank;
	save = opt->to_printf;
	if (opt->flags[FL] == 0)
		opt->to_printf = ft_strjoin(tempo, opt->to_printf);
	else
		opt->to_printf = ft_strjoin(opt->to_printf, tempo);
	free(save);
	free(tempo);
}

void		apply_width(t_options *opt)
{
	size_t	len;
	int		blank;

	if (opt->to_printf[0] == '0' && opt->flags[FSP] == 1
	&& (opt->conversion >= UD && opt->conversion <= I))
		opt->width += 1;
	len = ft_strlen(opt->to_printf);
	if ((blank = (opt->width) - len) > 0)
	{
		if (opt->to_printf[0] == '-' && opt->flags[FZ] == 1)
		{
			apply_width_for_less(opt, blank);
			return ;
		}
		if (opt->conversion == 2)
		{
			apply_width_for_ptr(opt, blank);
			return ;
		}
		apply_width_for_c(opt, blank);
	}
}
