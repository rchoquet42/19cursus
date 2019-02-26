/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 12:32:32 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/20 15:56:14 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cc;
	int		i;

	i = 0;
	cc = (char)c;
	while (*s && *s != cc)
		s++;
	if (*s == cc || *s != '\0')
		return ((char*)s);
	return (NULL);
}
