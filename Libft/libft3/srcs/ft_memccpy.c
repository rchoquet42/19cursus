/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/15 14:08:25 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:15:58 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char			*t_dst;
	const unsigned char		*t_src;
	unsigned char			cc;

	cc = (unsigned char)c;
	t_dst = dst;
	t_src = src;
	while (n > 0)
	{
		if (*t_src == cc)
		{
			*t_dst = *t_src;
			t_dst++;
			return (t_dst);
		}
		*t_dst = *t_src;
		t_dst++;
		t_src++;
		n--;
	}
	return (NULL);
}
