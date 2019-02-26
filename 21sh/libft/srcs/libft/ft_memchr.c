/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/17 23:05:24 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/20 15:54:02 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char *cs;

	cs = (const unsigned char*)s;
	while (n-- > 0)
	{
		if (*cs == (unsigned char)c)
			return ((void*)cs);
		cs++;
	}
	return (NULL);
}
