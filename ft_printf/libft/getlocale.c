/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getlocale.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/02 15:59:38 by rchoquet          #+#    #+#             */
/*   Updated: 2018/08/21 01:13:27 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*getlocale(int cat)
{
	return (setlocale(cat, NULL));
}