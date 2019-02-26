/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:37:24 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/12 12:13:16 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**split_var_env(char *var)
{
	char	*tmp;
	char	**path_tab;
	char	*save;

	tmp = get_value(var);
	if (tmp == NULL)
		return (NULL);
	path_tab = ft_split_char(tmp, ':');
	return (path_tab);
}

static int	exec_bin(char *path, char **argv)
{
	int		i;
	pid_t	pid;

	g_sub_process = 1;
	pid = fork();
	if (pid == 0)
	{
		printf("path %s\n", path);
		if ((i = execve(path, argv, g_env)) == -1)
		{
			ft_putstr_fd("execve failed\n", 2);
			g_sub_process = 0;
			exit(0);
		}
	}
	if (pid > 0)
		wait(NULL);
	g_sub_process = 0;
	return (0);
}

static void	join_path(char *file_name, char **argv)
{
	int			i;
	char		*path;
	struct stat	st;
	char		**path_tab;

	if (!(path_tab = split_var_env("PATH")))
		return (ft_putstr_fd("PATH: Undefined variable.\n", 2));
	i = 0;
	file_name = ft_strjoin("/", file_name);
	while (path_tab[i])
	{
		if (!(path = ft_strjoin(path_tab[i++], file_name)))
			return ;
		if ((lstat(path, &st)) == -1)
			free(path);
		else
		{
			exec_bin(path, argv);
			free(path);
			break ;
		}
	}
	(path_tab[i] == NULL ? display_error(file_name) : 0);
	free_tab(path_tab);
	free(file_name);
}

void		launch_bin(char *path, char **argv)
{
	struct stat	st;

	if ((lstat(path, &st)) != -1)
	{
		if (st.st_mode & S_IXUSR)
			exec_bin(path, argv);
		else
			ft_printf_fd(2, "zsh: command not found: %s\n", path);
	}
	else
		join_path(path, argv);
}
