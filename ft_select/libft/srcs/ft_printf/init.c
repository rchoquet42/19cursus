/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/20 23:58:51 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/07 19:03:16 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**0 = s, 1 = S, 2 = p, 3 = D, 4 = d, 5 = i, 6 = o, 7 = O,
**8 = U, 9 = u, 10 = x, 11 = X,12 = c, 13 = C, 14 = %, 15 = ?
*/

void	fonction_tab(t_options *opt)
{
	opt->ftab[LS] = &printf_string;
	opt->ftab[US] = &printf_wchar_t;
	opt->ftab[P] = &printf_ptr;
	opt->ftab[UD] = &printf_ldecimal;
	opt->ftab[LD] = &printf_decimal;
	opt->ftab[I] = &printf_decimal;
	opt->ftab[LO] = &printf_octal;
	opt->ftab[UO] = &printf_loctal;
	opt->ftab[UU] = &printf_ludecimal;
	opt->ftab[LU] = &printf_udecimal;
	opt->ftab[LX] = &printf_hexa;
	opt->ftab[UX] = &printf_hexa_cap;
	opt->ftab[LC] = &printf_char;
	opt->ftab[UC] = &printf_wint_t;
	opt->ftab[POURC] = &printf_pourcent;
	opt->ftab[LB] = &printf_binaire;
	opt->ftab[16] = &printf_do_nothing;
}

/*
**initialise la structure
*/

void	init_opt(t_options *opt)
{
	opt->width = 0;
	opt->precision = -1;
	opt->length = "0";
	opt->blank = ' ';
	opt->conversion = -1;
	opt->c_char = '-';
	opt->to_printf = ft_strdup("");
	fonction_tab(opt);
}

/*
**Reset la structure
*/

void	reset_opt(t_options *opt)
{
	int	x;

	x = 0;
	opt->width = 0;
	opt->precision = -1;
	if (ft_strcmp(opt->length, "0") != 0)
		free(opt->length);
	opt->length = "0";
	opt->blank = ' ';
	opt->c_char = '-';
	opt->conversion = -1;
	free(opt->to_printf);
}
