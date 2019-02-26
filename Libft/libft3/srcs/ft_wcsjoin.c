/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 18:00:09 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:25:38 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

wchar_t	*ft_wcsjoin(const wchar_t *s1, const wchar_t *s2)
{
	unsigned long	len;
	wchar_t			*res;

	if (!s1 || !s2)
		return ((wchar_t*)NULL);
	len = ft_wcslen(s1) + ft_wcslen(s2) + 1;
	if (!(res = (wchar_t*)malloc(sizeof(wchar_t) * len)))
		return ((wchar_t*)NULL);
	res = ft_wcscpy(res, s1);
	ft_wcslcat(res, s2, len);
	return (res);
}
