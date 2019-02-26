/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_octal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:59:29 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/30 14:46:57 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_octal(t_options *opt, va_list ap)
{
	char	*str;
	char	*tmp;

	if (!ft_strcmp(opt->length, "z"))
		str = uitoa_base(8, va_arg(ap, size_t));
	else if (!ft_strcmp(opt->length, "j"))
		str = uitoa_base(8, va_arg(ap, uintmax_t));
	else if (!ft_strcmp(opt->length, "ll"))
		str = uitoa_base(8, va_arg(ap, unsigned long long));
	else if (!ft_strcmp(opt->length, "l"))
		str = uitoa_base(8, va_arg(ap, unsigned long));
	else if (!ft_strcmp(opt->length, "h"))
		str = uitoa_base(8, (unsigned short)va_arg(ap, int));
	else if (!ft_strcmp(opt->length, "hh"))
		str = uitoa_base(8, (unsigned char)va_arg(ap, int));
	else
		str = uitoa_base(8, va_arg(ap, unsigned int));
	tmp = opt->to_printf;
	opt->to_printf = ft_strdup(str);
	free(str);
	free(tmp);
}
