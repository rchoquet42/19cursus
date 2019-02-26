/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_wint_t.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:49:45 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/20 15:37:10 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_wint_t(t_options *opt, va_list ap)
{
	wint_t	c;
	char	*save;

	c = va_arg(ap, wint_t);
	if (c > 0x10ffff || c < 0 || (c >= 0xd800 && c <= 0xdfff))
		exit(0);
	if (c != '\0')
	{
		save = opt->to_printf;
		opt->to_printf = ft_unicode_conv(c);
		free(save);
	}
	else
	{
		save = opt->to_printf;
		opt->to_printf = ft_strnew(0);
		opt->to_printf[0] = 0;
		opt->width -= 1;
		opt->c_char = 0;
		free(save);
	}
}
