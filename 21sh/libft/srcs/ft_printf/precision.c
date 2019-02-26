/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:06:25 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/20 15:35:18 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		check_precision(const char **format, t_options *opt)
{
	int		i;
	char	*temp_prec;

	i = 0;
	if (**format == '.')
	{
		(*format)++;
		while (ft_isdigit((*format)[i]))
			i++;
		if (i == 0)
			opt->precision = 0;
		else
		{
			temp_prec = ft_strsub(*format, 0, i);
			opt->precision = ft_atoi(temp_prec);
			free(temp_prec);
			(*format) += i;
		}
	}
}

static void	precision_for_p(t_options *opt)
{
	char	*temp;
	char	*save;
	int		len;
	int		blank;

	if (ft_strcmp(opt->to_printf, "0x0") == 0 && opt->precision == 0)
		swiss(opt, 42);
	else if (opt->precision > (blank = (ft_strlen(opt->to_printf) - 2)))
	{
		len = opt->precision - blank;
		if (!(save = (char*)malloc(sizeof(char) * (len + 1))))
			return ;
		ft_memset(save, '0', len);
		save[len] = '\0';
		temp = opt->to_printf;
		len = ft_strlen(opt->to_printf);
		opt->to_printf = ft_strjoin(save, ft_strsub(opt->to_printf, 2, len));
		free(temp);
		temp = opt->to_printf;
		opt->to_printf = ft_strjoin("0x", temp);
		free(temp);
		free(save);
	}
}

static void	precision_for_less(t_options *opt)
{
	int		len;
	char	*save;
	char	*temp;
	char	*sub;

	len = opt->precision - ft_strlen(opt->to_printf) + 2;
	if (!(save = (char*)malloc(sizeof(char) * (len + 1))))
		return ;
	ft_memset(save, '0', len);
	save[len] = '\0';
	save[0] = '-';
	temp = opt->to_printf;
	sub = ft_strsub(opt->to_printf, 1, ft_strlen(opt->to_printf));
	opt->to_printf = ft_strjoin(save, sub);
	free(sub);
	free(temp);
	free(save);
}

static void	precision_not_for_less(t_options *opt)
{
	int		len;
	char	*save;
	char	*temp;

	len = opt->precision - ft_strlen(opt->to_printf);
	if (!(save = (char*)malloc(sizeof(char) * (len + 1))))
		return ;
	save[len] = '\0';
	ft_memset(save, '0', len);
	temp = opt->to_printf;
	opt->to_printf = ft_strjoin(save, temp);
	free(temp);
	free(save);
}

void		apply_precision(t_options *opt)
{
	int		len;
	char	*save;
	char	*temp;

	if ((opt->conversion == LS || opt->conversion == US) && opt->precision >= 0)
	{
		len = ft_strlen(opt->to_printf);
		if (opt->precision < len)
			swiss(opt, 0);
	}
	else if (opt->conversion == P)
		precision_for_p(opt);
	else if (opt->conversion < LC || opt->conversion == 15)
	{
		len = ft_strlen(opt->to_printf);
		if (opt->precision < len)
		{
			if (opt->precision == 0 && (ft_strcmp(opt->to_printf, "0")) == 0)
				swiss(opt, 19);
		}
		else if (opt->precision > len && opt->to_printf[0] != '-')
			precision_not_for_less(opt);
		else if ((opt->precision + 1) > len && opt->to_printf[0] == '-')
			precision_for_less(opt);
	}
}
