/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_pourcent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 01:03:25 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:28:39 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	printf_pourcent(t_options *opt, va_list ap)
{
	char	*tmp;

	tmp = opt->to_printf;
	opt->to_printf = ft_strdup("%");
	free(tmp);
}
