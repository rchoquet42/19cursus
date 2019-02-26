/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 01:06:12 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/16 10:28:17 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_env(void)
{
	int	i;

	i = 0;
	while (g_env[i])
	{
		ft_printf("%s\n", g_env[i]);
		i++;
	}
}

void	display_malloc_failed(void)
{
	ft_printf_fd(2, "allocation failed\n");
}
