/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 19:05:42 by rchoquet          #+#    #+#             */
/*   Updated: 2018/12/17 21:36:50 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int	main(int argc, char **argv, char **env)
{
	init_all();
	display_prompt();
	argc = 0;
	argv = NULL;
	env = NULL;
	read_line();
	sig_end(0);
	return (0);
}
