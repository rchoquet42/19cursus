/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_loctal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:04:49 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:28:18 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printf_loctal(t_options *opt, va_list ap)
{
	if (opt->length[0] == 'h' || opt->length[0] == '0')
		opt->length = "l";
	opt->conversion = LO;
	printf_octal(opt, ap);
}
