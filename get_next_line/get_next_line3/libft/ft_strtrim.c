/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 20:50:39 by rchoquet          #+#    #+#             */
/*   Updated: 2018/06/20 14:17:33 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned long	i;
	char			*res;
	unsigned long	len;
	unsigned long	j;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	j = len - 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (i == len)
		return (ft_strdup(""));
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j--;
	if ((ft_strlen(s) - j) + i + 1 == len)
		return (ft_strdup(s));
	if (!(res = ft_strsub(s, i, (j - i + 1))))
		return ((char*)NULL);
	return (res);
}
