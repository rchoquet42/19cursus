/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 02:24:16 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/19 00:13:07 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	*free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (NULL);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

int		free_on_exit(char *line, char **cmd)
{
	free(line);
	free_tab(g_env);
	free_tab(g_env_save);
	free_tab(cmd);
	ft_printf("exit\n");
	return (0);
}

char	*free_line(char *str)
{
	if (str != NULL)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}
