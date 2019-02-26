/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 12:11:27 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/28 22:55:03 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	just_do_it(const char **format, t_options *opt, va_list ap)
{
	int i;

	i = 0;
	init_opt(opt);
	check_all(format, opt);
	opt->ftab[opt->conversion](opt, ap);
	apply_options(opt);
	i += display(opt);
	reset_opt(opt);
	return (i);
}

int			ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;
	t_options	opt;

	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
			i += just_do_it(&format, &opt, ap);
		else
		{
			format += (*format == '%' ? 1 : 0);
			write(1, &(*format), 1);
			i++;
		}
		format += (*format != '\0' ? 1 : 0);
	}
	va_end(ap);
	return (i);
}

/*
** Rassemble toutes les informations dans la structure t_options
*/

void		check_all(const char **format, t_options *opt)
{
	(*format)++;
	check_flags(format, opt);
	check_width(format, opt);
	check_precision(format, opt);
	check_length(format, opt);
	check_conversion(format, opt);
	flags_overrides(opt);
}

/*
** Applique les options dans un certains ordre en fct de la conversion
*/

void		apply_options(t_options *opt)
{
	if (opt->to_printf == NULL)
		opt->to_printf = ft_strdup("(null)");
	apply_precision(opt);
	if ((opt->conversion == LX || opt->conversion == UX)
	&& opt->flags[FH] == 1 && opt->flags[FZ] == 0)
	{
		(opt->c_char == '0' ? 0 : hashtag(opt));
		apply_add_space(opt);
		apply_width(opt);
	}
	else if ((opt->conversion == LX || opt->conversion == UX)
	&& opt->flags[FH] == 1 && opt->flags[FZ] == 1)
	{
		opt->width -= (ft_strcmp(opt->to_printf, "0") != 0 ? 2 : 0);
		apply_add_space(opt);
		apply_width(opt);
		(opt->c_char == '0' ? 0 : hashtag(opt));
	}
	else
		apply_options_else(opt);
}

void		apply_options_else(t_options *opt)
{
	if (opt->flags[FH] == 1)
		hashtag(opt);
	if (opt->width > (int)ft_strlen(opt->to_printf) && opt->flags[FZ] == 1)
	{
		if (opt->conversion >= UD && opt->conversion <= I
		&& ((opt->flags[FP] == 1 && opt->to_printf[0] != '-')
		|| (ft_strcmp(opt->to_printf, "0") == 0 && opt->flags[FSP] == 1)))
			opt->width -= 1;
		apply_width(opt);
		apply_add_space(opt);
	}
	else
	{
		apply_add_space(opt);
		apply_width(opt);
	}
}
