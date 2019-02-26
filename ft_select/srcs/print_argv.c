/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:46:04 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/27 10:29:31 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

bool	print_argv(t_argv **begin, t_argv **end, t_maxinfo *max)
{
	while (!(check_winsize(max)))
	{
		display_toosmall();
		while (!change_winsize())
			;
	}
	display_select(begin, end, max);
	return (TRUE);
}
