/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_udecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:36:05 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:29:00 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printf_udecimal(t_options *opt, va_list ap)
{
	char	*str;
	char	*tmp;

	if (!ft_strcmp(opt->length, "hh"))
		str = uitoa_base(10, (unsigned char)va_arg(ap, int));
	else if (!ft_strcmp(opt->length, "h"))
		str = uitoa_base(10, (unsigned short)va_arg(ap, int));
	else if (!ft_strcmp(opt->length, "l"))
		str = uitoa_base(10, va_arg(ap, unsigned long));
	else if (!ft_strcmp(opt->length, "ll"))
		str = uitoa_base(10, va_arg(ap, unsigned long long));
	else if (!ft_strcmp(opt->length, "j"))
		str = uitoa_base(10, va_arg(ap, uintmax_t));
	else if (!ft_strcmp(opt->length, "z"))
		str = uitoa_base(10, va_arg(ap, size_t));
	else
		str = uitoa_base(10, va_arg(ap, unsigned int));
	tmp = opt->to_printf;
	opt->to_printf = str;
	free(tmp);
}
