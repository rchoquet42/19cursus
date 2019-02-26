/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:34:48 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/16 15:14:34 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*get_env(char *name)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strcmp_char(name, g_env[i], '=') == 0)
			return (g_env[i]);
		i++;
	}
	return (NULL);
}

int			get_env_id(char *name)
{
	int		i;

	i = 0;
	while (g_env[i])
	{
		if (ft_strcmp_char(name, g_env[i], '=') == 0)
			return (i);
		i++;
	}
	return (i);
}

static int	modif_env(char **cmd)
{
	char	**param_setenv;
	int		i;

	i = 1;
	while (ft_strchr(cmd[i], '=') != NULL)
	{
		param_setenv = ft_split_char(cmd[i], '=');
		ft_setenv(param_setenv[0], param_setenv[1]);
		free_tab(param_setenv);
		i++;
	}
	return (i);
}

void		build_env(char **cmd)
{
	int		pid;
	char	**param_setenv;
	int		i;
	int		a;

	if (cmd[1] == NULL)
		display_env();
	else
	{
		pid = fork();
		if (pid == 0)
		{
			i = modif_env(cmd);
			param_setenv = ft_shift_tab(cmd, i);
			if ((a = is_my_build_in(cmd[i])) >= 0)
				exec_my_build(a, param_setenv);
			else
				launch_bin(cmd[i], param_setenv);
			free_tab(param_setenv);
			exit(0);
		}
		else if (pid > 0)
			wait(NULL);
		return ;
	}
}

int			get_env_len(void)
{
	int	i;

	i = 0;
	while (g_env[i])
		i++;
	return (i);
}
