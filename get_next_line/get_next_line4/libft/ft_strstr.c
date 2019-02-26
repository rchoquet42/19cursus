/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:04:05 by rchoquet          #+#    #+#             */
/*   Updated: 2018/06/18 14:51:05 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	unsigned long	j;
	char			*temp;

	if (!ft_strcmp("", needle))
		return ((char *)haystack);
	while (*haystack)
	{
		temp = (char *)haystack;
		j = 0;
		while (needle[j] == *haystack)
		{
			if (j == ft_strlen(needle) - 1)
				return (temp);
			j++;
			haystack++;
		}
		haystack = ++temp;
	}
	return (NULL);
}
