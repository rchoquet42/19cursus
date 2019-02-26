/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 20:36:40 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:20:31 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned long	len;
	char			*res;

	if (!s1 || !s2)
		return ((char*)NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	if (!(res = (char*)malloc(sizeof(char) * len)))
		return ((char*)NULL);
	res = ft_strcpy(res, s1);
	ft_strlcat(res, s2, len);
	return (res);
}
