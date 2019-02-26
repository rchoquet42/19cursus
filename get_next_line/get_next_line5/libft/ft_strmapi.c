/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 17:18:18 by rchoquet          #+#    #+#             */
/*   Updated: 2018/06/18 17:25:39 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*res;
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (*s != '\0')
	{
		res[i] = f(i, *s);
		i++;
		s++;
	}
	res[i] = '\0';
	return (res);
}
