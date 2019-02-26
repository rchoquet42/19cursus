/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/20 16:49:31 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/28 22:41:16 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	just_do_it_fd(const char **f, t_options *opt, va_list ap, int fd)
{
	int i;

	i = 0;
	init_opt(opt);
	check_all(f, opt);
	opt->ftab[opt->conversion](opt, ap);
	apply_options(opt);
	i += display_fd(opt, fd);
	reset_opt(opt);
	return (i);
}

int			ft_printf_fd(int fd, const char *format, ...)
{
	int			i;
	va_list		ap;
	t_options	opt;

	if (fd < 0)
		return (-1);
	i = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
			i += just_do_it_fd(&format, &opt, ap, fd);
		else
		{
			format += (*format == '%' ? 1 : 0);
			write(fd, &(*format), 1);
			i++;
		}
		format += (*format != '\0' ? 1 : 0);
	}
	va_end(ap);
	return (i);
}

int			display_fd(t_options *opt, int fd)
{
	int		i;
	char	c;

	c = 0;
	i = ft_strlen(opt->to_printf);
	if ((opt->conversion == LC || opt->conversion == UC) && opt->c_char == 0)
	{
		i++;
		if (opt->width > 0)
		{
			if (opt->flags[FL] == 0)
				ft_putstr_fd(opt->to_printf, fd);
			write(1, &c, 1);
			if (opt->flags[FL] == 1)
				ft_putstr_fd(opt->to_printf, fd);
			return (i);
		}
		else
			write(fd, &c, 1);
	}
	ft_putstr_fd(opt->to_printf, fd);
	return (i);
}
