/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wchar_t.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 14:35:56 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:29:16 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printf_wchar_t(t_options *opt, va_list ap)
{
	wchar_t		*str;
	int			i;
	char		*tmp;
	int			preci;

	preci = (opt->precision == -1 ? 0 : 1);
	i = -1;
	str = va_arg(ap, wchar_t*);
	if (str == NULL)
	{
		opt->to_printf = NULL;
		return ;
	}
	while (str[++i])
	{
		if (str[i] > 0x10ffff || str[i] < 0
		|| (str[i] >= 0xd800 && str[i] <= 0xdfff))
			exit(0);
		tmp = ft_unicode_conv(str[i]);
		if ((opt->precision -= ft_strlen(tmp)) < 0 && preci)
			break ;
		free(opt->to_printf);
		opt->to_printf = ft_strjoin(opt->to_printf, tmp);
		free(tmp);
	}
}
