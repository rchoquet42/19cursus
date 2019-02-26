/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ldecimal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:46:21 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/30 11:52:06 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_ldecimal(t_options *opt, va_list ap)
{
	if (opt->length[0] == 'h' || opt->length[0] == '0')
		opt->length = "l";
	opt->conversion = LD;
	printf_decimal(opt, ap);
}
