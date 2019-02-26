/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 20:32:09 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:27:35 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printf_char(t_options *opt, va_list ap)
{
	unsigned char	c;
	char			*str;
	int				len;

	if (ft_strcmp(opt->length, "l") == 0)
	{
		opt->conversion = 13;
		printf_wint_t(opt, ap);
		return ;
	}
	c = (unsigned char)va_arg(ap, int);
	len = (c == 0 ? 1 : 2);
	if (!(str = (char*)malloc(sizeof(char) * len)))
		return ;
	if (len == 2)
	{
		str[0] = c;
		str[1] = '\0';
	}
	else
		str[0] = 0;
	opt->width -= (c == 0 ? 1 : 0);
	opt->c_char = c;
	opt->to_printf = str;
}
