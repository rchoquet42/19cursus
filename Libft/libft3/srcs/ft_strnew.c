/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 16:15:36 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/06 14:22:11 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	if (!(res = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	return (ft_memset(res, '\0', size + 1));
}
