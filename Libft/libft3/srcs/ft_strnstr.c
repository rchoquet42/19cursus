/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 10:17:27 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:22:19 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	j;
	const char		*temp;

	i = 0;
	if (!ft_strcmp("", needle))
		return ((char *)haystack);
	while (*haystack && i < len)
	{
		temp = (char *)haystack;
		j = 0;
		while (needle[j] == *haystack && (j + i) < len)
		{
			if (j == ft_strlen(needle) - 1)
				return ((char *)temp);
			j++;
			haystack++;
		}
		haystack = ++temp;
		i++;
	}
	return (NULL);
}
