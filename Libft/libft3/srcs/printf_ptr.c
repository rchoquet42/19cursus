/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 19:17:16 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:28:47 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printf_ptr(t_options *opt, va_list ap)
{
	char	*tmp;
	char	*tmp2;

	tmp = itoa_base(16, va_arg(ap, long int));
	tmp2 = opt->to_printf;
	opt->to_printf = ft_strjoin("0x", tmp);
	free(tmp);
	free(tmp2);
}
