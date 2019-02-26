/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 23:40:18 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/16 22:04:20 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_shift_tab(char **cmd, int i)
{
	int		len;
	char	**res;
	int		x;

	x = 0;
	len = 0;
	while (cmd[len] != NULL)
		len++;
	len -= i;
	if (!(res = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (x < len)
	{
		res[x] = ft_strdup(cmd[i]);
		x++;
		i++;
	}
	res[x] = NULL;
	return (res);
}

char	*get_value(char *key)
{
	int		i;
	char	*tmp;

	i = 0;
	while (g_env[i])
	{
		if (ft_strcmp_char(key, g_env[i], '=') == 0)
		{
			tmp = (ft_strchr(g_env[i], '='));
			tmp++;
			return (tmp);
		}
		i++;
	}
	return (NULL);
}
