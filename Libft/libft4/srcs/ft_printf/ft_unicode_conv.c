/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_conv.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/17 14:10:28 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/24 19:20:02 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_char4(wint_t c)
{
	char	t;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * 5)))
		return (NULL);
	t = (c >> 18) | 0xF0;
	res[0] = t;
	t = (((c >> 12) & 0x3F) | 0x80);
	res[1] = t;
	t = (((c >> 6) & 0x3F) | 0x80);
	res[2] = t;
	t = ((0x3F & c) | 0x80);
	res[3] = t;
	res[4] = '\0';
	return (res);
}

static char		*ft_char3(wint_t c)
{
	char	t;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * 4)))
		return (NULL);
	t = (c >> 12) | 0xE0;
	res[0] = t;
	t = (((c >> 6) & 0x3F) | 0x80);
	res[1] = t;
	t = ((0x3F & c) | 0x80);
	res[2] = t;
	res[3] = '\0';
	return (res);
}

static	char	*ft_char2(wint_t c)
{
	char	t;
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * 3)))
		return (NULL);
	t = (c >> 6) | 0xC0;
	res[0] = t;
	t = ((0x3F & c) | 0x80);
	res[1] = t;
	res[2] = '\0';
	return (res);
}

static char		*ft_char1(wint_t c)
{
	char	*res;

	if (!(res = (char*)malloc(sizeof(char) * 2)))
		return (NULL);
	res[0] = (char)c;
	res[1] = '\0';
	return (res);
}

char			*ft_unicode_conv(wint_t wc)
{
	int	len;

	len = size_nbr(2, wc);
	if (len > 16 && len <= 21)
		return (ft_char4(wc));
	if (len > 11 && len <= 16)
		return (ft_char3(wc));
	if (len > 7 && len <= 11)
		return (ft_char2(wc));
	if (len <= 7)
		return (ft_char1(wc));
	return ((char*)NULL);
}
