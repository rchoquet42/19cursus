/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 18:13:26 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/20 17:22:23 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s)
		return ((char *)s);
	if (!(res = (char*)malloc(sizeof(char) * (len + 1))))
		return ((char *)NULL);
	res[len] = '\0';
	while (s[start] && i < len)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	return (res);
}
