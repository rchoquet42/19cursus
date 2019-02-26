/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 15:21:36 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/18 14:08:31 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	sig_handler(int sig_int)
{
	char	*tmp;

	if (g_sub_process == 0)
	{
		ft_printf("\n");
		display_prompt();
	}
	else
	{
		ft_printf("\n");
		g_sub_process = 0;
	}
}
