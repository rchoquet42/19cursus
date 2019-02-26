/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ababa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/18 00:27:04 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/19 00:40:18 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	nbr_word(char *str)
{
	int		i;
	char	quote;

	i = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\t'
		|| *str == '\n' || *str == '"' || *str == '\'')
		{
			if ((*str == '"' || *str == '\'') && (quote = *str) != '\0' && i++)
			{
				str++;
				while (*str != quote && *str != '\0')
					str++;
			}
			str++;
		}
		if (*str == '\0')
			return (i);
		i++;
		while (*str != ' ' && *str != '\t' && *str != '\n' && *str != '\0'
		&& *str != '"' && *str != '\'')
			str++;
	}
	return (i);
}

static int	start_word(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	return (i);
}

static int	end_word(char *str, int a)
{
	char	quote;

	quote = str[a];
	a++;
	if (quote != '"' && quote != '\''
	&& quote != ' ' && quote != '\t' && quote != '\n')
	{
		while (str[a] != ' ' && str[a] != '\t' && str[a] != '\n'
		&& str[a] != '"' && str[a] != '\'' && str[a] != '\0')
			a++;
	}
	else
		while (str[a] != quote && str[a] != '\0')
			a++;
	return (a);
}

static int	store_env(char **res, int i)
{
	char	*tmp;

	tmp = ((res[i]) + 1);
	tmp = get_value(tmp);
	if (tmp == NULL)
	{
		ft_putstr_fd("Undefined variable.\n", 2);
		return (0);
	}
	free(res[i]);
	res[i] = ft_strdup(tmp);
	return (1);
}

/*
** tab[0] = start, tab[1] = end, tab[2] index nbr de mots,
** tab[3] = index dans str, tab[4] = len de str, tab[5] = try
*/

char		**ft_split_argv(char *str)
{
	char	**res;
	int		tab[6];

	tab[2] = 0;
	tab[3] = 0;
	if ((tab[4] = nbr_word(str)) == 0)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char *) * (tab[4] + 1))))
		return (NULL);
	res[tab[4]] = NULL;
	while (tab[2] < tab[4])
	{
		tab[0] = start_word(str, tab[3]);
		tab[1] = end_word(str, tab[0]);
		tab[5] = (str[tab[0]] == '"' || str[tab[0]] == '\'' ? 1 : 0);
		if (!(res[tab[2]] = ft_strsub(str, tab[0] += tab[5], tab[1] - tab[0])))
			return (free_tab(res));
		if (res[tab[2]][0] == '$')
			if (store_env(res, tab[2]) == 0)
				return (free_tab(res));
		tab[3] = tab[1] + tab[5];
		tab[2]++;
	}
	return (res);
}
