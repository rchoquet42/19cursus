/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/19 12:52:26 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/25 21:38:48 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_l_info(t_info *tmp, t_max *max)
{
	if (tmp->type == 'l' && max->device == 1)
		ft_printf("%8lld %s %s %5s %s -> %s\n", tmp->size, tmp->month, tmp->day,
				tmp->hour, tmp->name, tmp->name_lnk);
	else if (tmp->type == 'l' && max->device == 0)
		ft_printf("%lld %s %s %5s %s -> %s\n", tmp->size, tmp->month, tmp->day,
				tmp->hour, tmp->name, tmp->name_lnk);
	else if ((tmp->type == 'c') || tmp->type == 'b')
		ft_printf("%3d, %3d %s %s %5s %s\n", tmp->major, tmp->minor, tmp->month,
				tmp->day, tmp->hour, tmp->name);
	else if (max->device == 1)
		ft_printf("%8lld %s %s %5s %s\n", tmp->size, tmp->month, tmp->day,
				tmp->hour, tmp->name);
	else
		ft_printf("%lld %s %s %5s %s\n", tmp->size, tmp->month, tmp->day,
				tmp->hour, tmp->name);
}

void		display_error(t_error *begin)
{
	t_error	*save;

	while (begin)
	{
		ft_printf_fd(2, "ls: %s: %s\n", begin->name, strerror(begin->erno));
		save = begin->next;
		free(begin->name);
		free(begin);
		begin = save;
	}
}

void		ft_usage(char illegal)
{
	ft_printf_fd(2, "ls: illegal option -- %c\n", illegal);
	ft_printf_fd(2, "usage: ft_ls [%s] [file ...]\n", FLAG);
}
