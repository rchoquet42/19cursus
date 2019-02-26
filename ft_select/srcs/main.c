/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 01:35:14 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/27 17:27:17 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int	main(int argc, char **argv, char **env)
{
	t_argv		*begin;
	t_argv		*end;
	char		*ve;
	t_maxinfo	*max;

	begin = NULL;
	end = NULL;
	if (argc == 1)
		return (usage());
	if (ttyslot() <= 0 || env == NULL || *env == NULL)
		return (env_not_found());
	max = create_chain(&begin, &end, argv);
	if (init_all(&begin, &end, &max) == -1)
	{
		free_linked_max(&begin, &end, &max);
		return (env_not_found());
	}
	catch_key(&begin, &end, max) == TRUE ? display_argv(&begin, max)
	: ft_putstr_fd(tgetstr("cl", NULL), 0);
	ve = tgetstr("ve", NULL);
	ft_putstr_fd(ve, 0);
	free_linked_max(&begin, &end, &max);
	sig_end(0);
	return (0);
}
