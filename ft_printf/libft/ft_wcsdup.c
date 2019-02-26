/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wcsdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 17:53:16 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/18 01:20:53 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdio.h>

wchar_t	*ft_wcsdup(const wchar_t *s)
{
	wchar_t	*res;
	int		len;

	if (s == NULL)
		return (NULL);
	len = ft_wcslen(s);
	if (!(res = (wchar_t*)malloc(sizeof(wchar_t) * len)))
		return (NULL);
	res[len--] = '\0';
	while (len >= 0)
	{
		res[len] = s[len];
		len--;
	}
	return (res);
}
