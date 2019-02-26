/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 02:24:41 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/19 00:41:14 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		go_home_u_drunk(void)
{
	char		*path;
	char		**home;
	int			i;
	char		*value;
	struct stat	st;

	i = 0;
	value = get_value("HOME");
	if (value == NULL)
		return (display_error_env_not_set("HOME"));
	home = ft_split_char(value, ':');
	while (home[i] != NULL && lstat(home[i], &st) == -1)
		i++;
	if (home[i] == NULL || (access(home[i], st.st_mode) == -1))
		return (display_error_dir(home[i]));
	chdir(home[i]);
	path = getcwd(NULL, 0);
	ft_setenv("OLDPWD", get_value("PWD"));
	ft_setenv("PWD", path);
	free(path);
	free_tab(home);
}

static void		go_oldpwd(void)
{
	char		**home;
	char		*value;
	struct stat	st;
	int			i;
	char		*path;

	i = 0;
	value = get_value("OLDPWD");
	if (value == NULL)
		return (display_error_env_not_set("OLDPWD"));
	home = ft_split_char(value, ':');
	while (home[i] != NULL && lstat(home[i], &st) == -1)
		i++;
	if (home[i] == NULL || (access(home[i], st.st_mode) == -1))
		return (display_error_dir(home[i]));
	chdir(home[i]);
	path = getcwd(NULL, 0);
	ft_setenv("OLDPWD", get_value("PWD"));
	ft_setenv("PWD", path);
	free(path);
	free_tab(home);
}

static void		go_cd(char *value)
{
	struct stat	st;
	int			i;
	char		*path;

	i = 0;
	if (lstat(value, &st) == -1)
		return (display_error_dir(NULL));
	if (access(value, st.st_mode) == -1)
		return (display_error_dir(value));
	if (chdir(value) == -1)
		return (display_error_dir(value));
	path = getcwd(NULL, 0);
	ft_setenv("OLDPWD", get_value("PWD"));
	ft_setenv("PWD", path);
	free(path);
}

static char		*join_home(char *cmd)
{
	char	*home;
	char	*res;
	char	*tmp;

	home = get_value("HOME");
	if (home == NULL)
	{
		display_error_env_not_set("HOME");
		return (NULL);
	}
	tmp = ft_strsub(cmd, 1, ft_strlen(cmd));
	if (!(res = ft_strjoin(home, tmp)))
		return (NULL);
	free(tmp);
	return (res);
}

void			build_cd(char **cmd)
{
	char	*res;

	if (cmd[1] == NULL || (ft_strcmp(cmd[1], "~") == 0))
		go_home_u_drunk();
	else if (ft_strcmp(cmd[1], "-") == 0)
		go_oldpwd();
	else
	{
		if (cmd[1][0] == '~')
		{
			if (!(res = join_home(cmd[1])))
				return ;
			free(cmd[1]);
			cmd[1] = res;
		}
		go_cd(cmd[1]);
	}
}
