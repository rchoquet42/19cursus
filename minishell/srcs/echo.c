/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:39:38 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/17 23:18:14 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	build_echo(char **cmd)
{
	int i;
	int opt;

	opt = 0;
	i = 1;
	while (cmd[i])
	{
		if (!ft_strcmp(cmd[i], "-n"))
		{
			opt = 1;
			i++;
			continue ;
		}
		ft_printf("%s", cmd[i]);
		if (cmd[i][0] == '\0')
		{
			i++;
			continue ;
		}
		i++;
		if (cmd[i] != NULL)
			ft_printf(" ");
	}
	(opt == 0 ? ft_printf("\n") : 0);
}
