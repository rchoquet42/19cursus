/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/06 18:25:50 by rchoquet          #+#    #+#             */
/*   Updated: 2018/09/29 19:00:10 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	do_it(char **argv, int i, t_info *begin, t_info *end)
{
	t_max	max;
	char	**dirs;
	t_util	*ut;

	ut = new_util(&begin, &end, i);
	init_max(&max);
	sort_files(argv, ut, &max);
	dirs = sort_dirs(argv, i);
	ft_ls(dirs, &begin, &end, &max);
	free_tab(dirs);
	free(ut);
}

int			main(int argc, char **argv)
{
	t_info	*begin;
	t_info	*end;
	int		i;
	int		tmp;

	begin = NULL;
	end = NULL;
	g_options = 0;
	i = 1;
	if (argc == 1)
	{
		create_chain_list(".", &begin, &end, 0);
		return (0);
	}
	while (((argc) > i) && (tmp = (check_options(argv[i]) != 0)))
	{
		i += tmp;
		if (ft_strcmp(argv[i - 1], "--") == 0)
			break ;
	}
	if (argc != i)
		do_it(argv, i, begin, end);
	else
		create_chain_list(".", &begin, &end, 0);
	return (0);
}
