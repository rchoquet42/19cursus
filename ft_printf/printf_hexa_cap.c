/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_hexa_cap.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 16:02:40 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/05 19:45:00 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_hexa_cap(t_options *opt, va_list ap)
{
	int		i;

	i = 0;
	printf_hexa(opt, ap);
	while (opt->to_printf[i])
	{
		opt->to_printf[i] = ft_toupper(opt->to_printf[i]);
		i++;
	}
}
