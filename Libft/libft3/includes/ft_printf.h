/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 12:22:27 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 15:39:51 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define CONV "sSpDdioOUuxXcC%b"
# define FLAGS "#0-+ "
# define LENGTH "hljz"
# define NFLAGS (sizeof(FLAGS) - 1)
# define NCONV (sizeof(CONV))
# define LS 0
# define US 1
# define P 2
# define UD 3
# define LD 4
# define I 5
# define LO 6
# define UO 7
# define UU 8
# define LU 9
# define LX 10
# define UX 11
# define LC 12
# define UC 13
# define POURC 14
# define LB 15

# define FH 0
# define FZ 1
# define FL 2
# define FP 3
# define FSP 4

# include <unistd.h>
# include <stdarg.h>
# include <locale.h>
# include "libft.h"
# include <wchar.h>
# include <limits.h>

/*
** tab flag = #, 0, -, +, ' '
*/
typedef struct	s_options
{
	int				flags[NFLAGS];
	int				width;
	int				precision;
	char			*length;
	int				conversion;
	char			blank;
	char			*to_printf;
	char			c_char;
	void			(*ftab[NCONV])(struct s_options*, va_list);
}				t_options;

/*
** ft_printf.c
*/
int				ft_printf(const char *format, ...);
static void		check_all(const char **format, t_options *opt);
static int		just_do_it(const char **format, t_options *opt, va_list ap);
static void		apply_options(t_options *opt);
static void		apply_options_else(t_options *opt);

/*
** flags.c
*/
void			check_flags(const char **format, t_options *opt);
void			flags_overrides(t_options *opt);
void			apply_add_space(t_options *opt);
static int		is_flag(char c, t_options *opt);

/*
** flags_options.c
*/
void			hashtag(t_options *opt);
void			add(t_options *opt);
void			space(t_options *opt);

/*
** width.c
*/
void			check_width(const char **format, t_options *opt);
void			apply_width(t_options *opt);
static void		apply_width_for_c(t_options *opt, int blank);
static void		apply_width_for_less(t_options *opt, int blank);
static void		apply_width_for_ptr(t_options *opt, int blank);

/*
** precision.c
*/
void			check_precision(const char **format, t_options *opt);
void			apply_precision(t_options *opt);
static void		precision_for_less(t_options *opt);
static void		precision_not_for_less(t_options *opt);

/*
** length.c
*/
void			check_length(const char **format, t_options *opt);
static int		is_length(char c);

/*
** conversion.c
*/
int				is_conversion(char c, t_options *opt);
void			check_conversion(const char **format, t_options *opt);

/*
** printf_fct
*/
void			printf_char(t_options *opt, va_list ag);
void			printf_hexa(t_options *opt, va_list ag);
void			printf_hexa_cap(t_options *opt, va_list ag);
void			printf_string(t_options *opt, va_list ag);
void			printf_decimal(t_options *opt, va_list ag);
static void		support(t_options *opt, char *str);
void			printf_ldecimal(t_options *opt, va_list ag);
void			printf_octal(t_options *opt, va_list ag);
void			printf_loctal(t_options *opt, va_list ag);
void			printf_ptr(t_options *opt, va_list ag);
void			printf_udecimal(t_options *opt, va_list ag);
void			printf_ludecimal(t_options *opt, va_list ag);
void			printf_wchar_t(t_options *opt, va_list ag);
void			printf_wint_t(t_options *opt, va_list ag);
void			printf_pourcent(t_options *opt, va_list ag);
void			printf_do_nothing(t_options *opt, va_list ag);
void			printf_binaire(t_options *opt, va_list ag);

/*
** itoa_base.c
*/
int				size_nbr(int base, unsigned long long nbr);
char			*itoa_base(int base, long long nbr);
char			*uitoa_base(int base, unsigned long long nbr);

/*
** display.c
*/
int				display(t_options *opt);

/*
** ft_unicode_conv.c
*/
char			*ft_unicode_conv(wint_t c);
static char		*ft_char4(wint_t c);
static char		*ft_char3(wint_t c);
static char		*ft_char2(wint_t c);
static char		*ft_char1(wint_t c);

/*
** init.c
*/
void			fonction_tab(t_options *opt);
void			reset_opt(t_options *opt);
void			init_opt(t_options *opt);

/*
** util.c
*/
void			swiss(t_options *opt, int c);

#endif
