/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 14:45:37 by rchoquet          #+#    #+#             */
/*   Updated: 2018/06/12 15:15:19 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "display.h"

int		main(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_display_file(argv[1]);
	}
	else if (argc == 1)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	return (0);
}
