/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 21:15:05 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/17 22:32:08 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

/*
** set, del or return prompt
*/

static char *store_prompt(short s, char *msg)
{
	static char	*prpt = NULL;

	if (s == SET_P)
	{
		if (prpt == NULL && msg != NULL)
			prpt = ft_strdup(msg);
		else if (prpt != NULL && msg != NULL)
		{
			ft_strdel(&prpt);
			prpt = ft_strdup(prpt);
		}
	}
	else if (s == GET_P)
		return (prpt);
	else if (s == DEL_P)
		ft_strdel(&prpt);
	return (NULL);
}

char	*get_prompt(void)
{
	return (store_prompt(GET_P, NULL));
}

void	set_prompt(char *msg)
{
	store_prompt(SET_P, msg);
}

void	del_prompt(void)
{
	store_prompt(DEL_P, NULL);
}

void	display_prompt(void)
{
	ft_printf("%s>", get_prompt());
}
