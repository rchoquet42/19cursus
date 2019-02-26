/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 17:11:28 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/24 12:41:54 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	printf_string(t_options *opt, va_list ap)
{
	char	*tmp;
	char	*tmp2;

	if (!ft_strcmp(opt->length, "l"))
	{
		opt->conversion = 1;
		printf_wchar_t(opt, ap);
		return ;
	}
	tmp = va_arg(ap, char*);
	if (tmp == NULL)
		tmp = ft_strdup("(null)");
	tmp2 = opt->to_printf;
	opt->to_printf = ft_strdup(tmp);
	free(tmp2);
}
