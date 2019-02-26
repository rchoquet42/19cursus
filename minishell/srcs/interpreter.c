/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interpreteur.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 22:09:58 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/19 00:19:14 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_my_build(int i, char **cmd)
{
	if (i == 0)
		build_echo(cmd);
	else if (i == 1)
		build_cd(cmd);
	else if (i == 2)
		build_env(cmd);
	else if (i == 3)
		build_setenv(cmd);
	else if (i == 4)
		build_unsetenv(cmd);
	else if (i == 5)
		build_resetenv(cmd);
	else if (i == 6)
		build_setpcolor(cmd);
}

int		is_my_build_in(char *cmd)
{
	if (!ft_strcmp(cmd, "echo"))
		return (0);
	else if (!ft_strcmp(cmd, "cd"))
		return (1);
	else if (!ft_strcmp(cmd, "env"))
		return (2);
	else if (!ft_strcmp(cmd, "setenv"))
		return (3);
	else if (!ft_strcmp(cmd, "unsetenv"))
		return (4);
	else if (!ft_strcmp(cmd, "resetenv"))
		return (5);
	else if (!ft_strcmp(cmd, "setpcolor"))
		return (6);
	return (-1);
}

int		interpreter(char *line, void (*f[NBUILD])(char **))
{
	char	**cmd;
	int		i;
	char	*tmp;
	char	*save;

	tmp = line;
	tmp = wait_quote(line);
	if (tmp == NULL)
		return (1);
	cmd = ft_split_argv(tmp);
	if (cmd == NULL)
		return (1);
	if (!ft_strcmp("exit", cmd[0]))
	{
		free_tab(cmd);
		return (-1);
	}
	else if ((i = is_my_build_in(cmd[0])) >= 0)
		f[i](cmd);
	else
		launch_bin(cmd[0], cmd);
	free_tab(cmd);
	if (ft_strcmp(tmp, line) != 0)
		free(tmp);
	return (1);
}
