/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcslcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 17:58:07 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/20 15:59:36 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wcslcat(wchar_t *dst, const wchar_t *src, size_t size)
{
	unsigned long i;
	unsigned long j;
	unsigned long len;

	j = 0;
	i = ft_wcslen(dst);
	len = i;
	if (size < i)
		return (ft_wcslen(src) + size);
	while (i < size - 1)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (len + ft_wcslen(src));
}
