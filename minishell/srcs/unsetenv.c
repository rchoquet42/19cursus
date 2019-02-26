/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 00:48:31 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/10 01:07:23 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	build_unsetenv(char **cmd)
{
	int		i;
	int		tmp;

	i = 1;
	while (cmd[i])
	{
		tmp = get_env_id(cmd[i]);
		if (g_env[tmp] != NULL)
			realloc_env((get_env_len() - 1), tmp);
		i++;
	}
	if (i == 1)
		display_error_unsetenv();
}
