/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_and_free1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 15:40:10 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/17 15:43:20 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_and_free1(char *s1, char const *s2)
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
	ft_strdel(&s1);
	return (res);
}
