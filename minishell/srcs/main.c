/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 22:00:15 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/18 22:34:54 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		main(int argc, char **argv, char **envv)
{
	char	*line;
	void	(*ftab[NBUILD])(char **);
	int		i;
	char	**cmd;

	init_all(envv, ftab);
	display_prompt();
	while (1)
		while ((get_next_line(0, &line)) > 0)
		{
			if (line[0] != '\0')
				if ((cmd = ft_split_char(line, ';')))
				{
					i = 0;
					while (cmd[i])
						if (interpreter(cmd[i++], ftab) < 0)
							return (free_on_exit(line, cmd));
					free_tab(cmd);
				}
			free(line);
			display_prompt();
		}
	free_tab(g_env);
	free_tab(g_env_save);
	return (0);
}
