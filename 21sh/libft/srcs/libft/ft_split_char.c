/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 01:30:21 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/12 22:31:05 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nbr_word(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str == '\0')
			return (i);
		else
		{
			i++;
			while (*str != c && *str != '\0')
				str++;
		}
	}
	return (i);
}

static int	start_word(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] == c)
		i++;
	return (i);
}

static int	end_word(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] == c)
		i++;
	while (str[i] != c && str[i] != '\0')
		i++;
	return (i);
}

char		**ft_split_char(char *str, char c)
{
	char	**res;
	int		len;
	int		i;
	int		start;
	int		end;

	i = 0;
	if ((len = nbr_word(str, c)) == 0)
		return (NULL);
	if (!(res = (char**)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	res[len] = NULL;
	while (i < len)
	{
		end = end_word(str, c);
		start = start_word(str, c);
		res[i++] = ft_strsub(str, start, (end - start));
		str += end;
	}
	return (res);
}
