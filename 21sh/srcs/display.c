/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispay.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:17:13 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/17 19:19:29 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int			env_not_found(void)
{
	ft_printf_fd(2, "ERROR : Env not found\n");
	return (1);
}
