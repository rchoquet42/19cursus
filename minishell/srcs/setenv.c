/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 00:06:45 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/16 15:21:41 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_setenv(char *name, char *value)
{
	int		i;
	int		len;
	char	*save;
	char	*tmp;

	i = get_env_id(name);
	if (!(tmp = ft_strjoin(name, "=")))
		return (display_malloc_failed());
	if (!(save = ft_strjoin(tmp, value)))
	{
		free(tmp);
		return (display_malloc_failed());
	}
	free(tmp);
	if (g_env[i] != NULL)
		free(g_env[i]);
	else if (g_env[i] == NULL)
		realloc_env((i + 1), -1);
	g_env[i] = save;
}

void		build_setenv(char **cmd)
{
	int	i;

	i = 0;
	if (cmd[1] == NULL)
		return (display_env());
	while (cmd[1][i])
		if (ft_isalnum(cmd[1][i++]) == 0)
			return (display_error_setenv());
	if (cmd[2] == NULL)
		ft_setenv(cmd[1], "");
	else
		ft_setenv(cmd[1], cmd[2]);
}

void		realloc_env(int len, int index_del)
{
	char	**tmp;
	int		n;
	int		o;

	n = 0;
	o = 0;
	if (!(tmp = (char**)malloc(sizeof(char*) * (len + 1))))
		return (display_malloc_failed());
	tmp[len] = NULL;
	while (n < len)
	{
		if (o == index_del)
		{
			o++;
			continue ;
		}
		tmp[n] = ft_strdup(g_env[o]);
		n++;
		o++;
	}
	free_tab(g_env);
	g_env = tmp;
}
