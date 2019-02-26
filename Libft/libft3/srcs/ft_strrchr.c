/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 13:12:54 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:22:27 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	cc;
	int		i;
	int		j;

	j = 0;
	cc = (char)c;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == cc)
			break ;
		i--;
	}
	if (i == -1)
		return (NULL);
	while (j != i)
	{
		s++;
		j++;
	}
	return ((char*)s);
}
