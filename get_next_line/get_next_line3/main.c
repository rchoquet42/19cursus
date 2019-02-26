/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 16:54:52 by rchoquet          #+#    #+#             */
/*   Updated: 2018/07/19 16:57:53 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int fd = open(argv[1], O_RDONLY);
	char	*str;
	argc = 0;
	while (get_next_line(fd, &str))
		printf("%s\n", str);

	return (1);
}
