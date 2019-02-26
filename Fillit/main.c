/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dazheng <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/23 10:27:52 by dazheng           #+#    #+#             */
/*   Updated: 2018/12/10 18:01:12 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int	main(int argc, char **argv)
{
	t_block	**begin;
	t_block *block;
	char	*res;
	int		count;
	int		size_map;

	block = NULL;
	begin = &block;
	if (argc == 2)
	{
		count = read_file(argv, begin);
		size_map = sizeof_map(count) + 1;
		res = new_map(size_map);
		while (fillit(*begin, res) == 0)
		{
			free(res);
			size_map = size_map + 1;
			res = new_map(size_map);
		}
		display(res, size_map);
		lst_free(begin);
		free(res);
		return (0);
	}
	ft_putstr("usage: fillit input_file\n");
}
