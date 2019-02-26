/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/18 21:54:55 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/20 15:58:42 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		if (*s == c)
		{
			while (*s == c)
				s++;
		}
		else
		{
			while (*s != c && *s != '\0')
				s++;
			count++;
		}
	}
	return (count);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		nbr_word;

	if (!s)
		return (NULL);
	nbr_word = count_word(s, c);
	if (!(tab = (char**)malloc(sizeof(char*) * nbr_word + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (i < nbr_word)
	{
		j = 0;
		while (*s == c && *s)
			s++;
		while (s[j] != c && s[j])
			j++;
		tab[i] = ft_strsub(s, 0, j);
		i++;
		s += j;
	}
	tab[i] = 0;
	return (tab);
}
