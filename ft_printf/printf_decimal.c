/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_decimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:25:52 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/30 17:39:24 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		printf_decimal(t_options *opt, va_list ap)
{
	char	*str;
	va_list	dst;
	int		prev;

	va_copy(dst, ap);
	prev = va_arg(dst, int);
	if (!ft_strcmp(opt->length, "z"))
		str = itoa_base(10, va_arg(ap, size_t));
	else if (!ft_strcmp(opt->length, "j"))
		str = itoa_base(10, va_arg(ap, intmax_t));
	else if (!ft_strcmp(opt->length, "ll"))
		str = itoa_base(10, va_arg(ap, long long));
	else if (!ft_strcmp(opt->length, "l"))
		str = itoa_base(10, va_arg(ap, long));
	else if (!ft_strcmp(opt->length, "h"))
		str = itoa_base(10, (short)va_arg(ap, int));
	else if (!ft_strcmp(opt->length, "hh"))
		str = itoa_base(10, (char)va_arg(ap, int));
	else
		str = itoa_base(10, va_arg(ap, int));
	support(opt, str);
	if (opt->flags[FSP] == 1 && opt->flags[FZ] == 1 && str[0] == '-')
		opt->width += 1;
}

static void	support(t_options *opt, char *str)
{
	free(opt->to_printf);
	opt->to_printf = NULL;
	opt->to_printf = ft_strdup(str);
	free(str);
}
