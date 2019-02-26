/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bracket_quote.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 13:26:33 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/18 22:30:51 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	bracket_quote(char *line)
{
	char	quote;
	int		len;
	int		i;

	i = -1;
	while (line[++i])
		if (line[i] == '"' || line[i] == '\'')
		{
			quote = line[i];
			len = i + 1;
			if (line[len] == '\0')
				return ((quote == '"' ? 0 : -1));
			while (line[len])
			{
				if (line[len] == quote)
				{
					(i = len);
					break ;
				}
				if (line[(len + 1)] == '\0')
					return ((quote == '"' ? 0 : -1));
				len++;
			}
		}
	return (1);
}

char		*wait_quote(char *line)
{
	char	*tmp;
	char	*save;
	char	*help;
	int		util[2];

	util[0] = 0;
	help = line;
	g_sub_process = 1;
	while (g_sub_process == 1 && ((util[1] = bracket_quote(help)) <= 0))
	{
		ft_printf("%s>", (util[1] == 0 ? "dquote" : "quote"));
		if (get_next_line(0, &tmp) > 0)
		{
			if (util[0]++ != 0)
				free(help);
			if (!(save = ft_strjoin(help, "\n")))
				return (NULL);
			if (!(help = ft_strjoin(save, tmp)))
				return (NULL);
			free(save);
			free(tmp);
		}
	}
	return (g_sub_process == 0 || (((g_sub_process = 0) > 0)) ?
	free_line(help) : help);
}
