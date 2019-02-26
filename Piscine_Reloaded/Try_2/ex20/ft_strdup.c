/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 11:42:23 by rchoquet          #+#    #+#             */
/*   Updated: 2018/06/12 12:04:49 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(char *src)
{
	int		i;
	char	*res;
	int		len;

	len = ft_strlen(src);
	i = 0;
	if (!(res = (char*)malloc(sizeof(res) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (src[i])
	{
		res[i] = src[i];
		i++;
	}
	return (res);
}
