/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcssub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 18:17:24 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:26:11 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

wchar_t	*ft_wcssub(wchar_t const *s, unsigned int start, size_t len)
{
	wchar_t			*res;
	unsigned int	i;

	i = 0;
	if (!s)
		return ((wchar_t *)s);
	if (!(res = (wchar_t *)malloc(sizeof(wchar_t) * (len + 1))))
		return ((wchar_t *)NULL);
	res[len] = '\0';
	while (i++ < start)
		s++;
	res = ft_wcsncpy(res, s, len);
	return (res);
}
