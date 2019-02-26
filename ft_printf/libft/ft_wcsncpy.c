/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/05 18:13:01 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/05 18:13:04 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wcsncpy(wchar_t *dst, const wchar_t *src, size_t len)
{
	unsigned long i;
	unsigned long real_len;

	real_len = ft_wcslen(src);
	i = 0;
	while (i < len)
	{
		if (i > real_len)
			dst[i] = '\0';
		else
			dst[i] = src[i];
		i++;
	}
	return (dst);
}
