/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:59:59 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/20 15:57:35 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	int		i;
	char	*temp;

	temp = (char*)s;
	i = 0;
	if (!s || !f)
		return (NULL);
	if (!(res = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (*temp != '\0')
	{
		res[i++] = f(*temp);
		temp++;
	}
	res[ft_strlen(s)] = '\0';
	return (res);
}
