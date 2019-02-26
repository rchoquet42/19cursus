/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_basic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 22:03:19 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/28 23:12:45 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int			find_nb_name_line(int nb_to_display, int nb_name_line)
{
	while ((nb_to_display - nb_name_line) < (nb_name_line - 1))
	{
		if (nb_to_display % nb_name_line == 0)
			break ;
		nb_name_line--;
	}
	return (nb_name_line);
}

void				display_basic(t_info **begin, t_info **end, t_max *max)
{
	struct winsize	sz;
	int				nb_name_line;
	int				save;
	t_info			*tmp;
	int				len;

	ioctl(0, TIOCGWINSZ, &sz);
	max->len_n = ((max->len_n / 8) + 1) * 8;
	save = sz.ws_col;
	tmp = ((g_options & OPT_LR) == 0 ? (*begin) : (*end));
	while (tmp)
	{
		ft_printf("%s", tmp->name);
		len = max->len_n - ft_strlen(tmp->name);
		tmp = ((g_options & OPT_LR) == 0 ? tmp->next : tmp->prev);
		if ((save -= max->len_n) < max->len_n || tmp == NULL)
		{
			save = sz.ws_col;
			ft_printf("\n");
		}
		else
			while (len-- != 0)
				ft_printf(" ");
	}
}
