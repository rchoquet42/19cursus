/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 23:03:27 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/18 22:34:57 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void			init_env(char **envv)
{
	int len;
	int	i;

	i = 0;
	len = 0;
	while (envv[len])
		len++;
	if (!(g_env = (char**)malloc(sizeof(char*) * (len + 1))))
		return ;
	g_env[len] = NULL;
	while (i < len)
	{
		g_env[i] = ft_strdup(envv[i]);
		i++;
	}
}

static void		init_env_save(char **envv)
{
	int len;
	int	i;

	i = 0;
	len = 0;
	while (envv[len])
		len++;
	if (!(g_env_save = (char**)malloc(sizeof(char*) * (len + 1))))
		return ;
	g_env_save[len] = NULL;
	while (i < len)
	{
		g_env_save[i] = ft_strdup(envv[i]);
		i++;
	}
}

void			init_all(char **envv, void (*f[NBUILD])(char **))
{
	signal(SIGINT, sig_handler);
	g_sub_process = 0;
	init_env(envv);
	init_env_save(envv);
	ft_setenv("PCOLOR", "CYAN");
	(f)[0] = &build_echo;
	(f)[1] = &build_cd;
	(f)[2] = &build_env;
	(f)[3] = &build_setenv;
	(f)[4] = &build_unsetenv;
	(f)[5] = &build_resetenv;
	(f)[6] = &build_setpcolor;
}
