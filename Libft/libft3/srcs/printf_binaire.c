/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_binaire.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 10:42:21 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:27:29 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printf_binaire(t_options *opt, va_list ap)
{
	char	*str;
	char	*save;

	str = itoa_base(2, va_arg(ap, int));
	save = opt->to_printf;
	opt->to_printf = ft_strdup(str);
	free(str);
	free(save);
}
