/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/26 14:26:52 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/26 18:57:09 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

t_argv		**save_begin(t_argv **begin_par)
{
	static t_argv	**begin = NULL;

	if (begin == NULL)
		begin = begin_par;
	return (begin);
}

t_argv		**save_end(t_argv **end_par)
{
	static t_argv	**end = NULL;

	if (end == NULL)
		end = end_par;
	return (end);
}

t_maxinfo	**save_max(t_maxinfo **max_par)
{
	static t_maxinfo	**max = NULL;

	if (max == NULL)
		max = max_par;
	return (max);
}

void		gotoxy(int x, int y)
{
	char *res;

	res = tgetstr("cm", NULL);
	ft_putstr_fd(tgoto(res, x, y), 0);
}
