/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resetenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <rchoquet@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 23:33:55 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/11 23:38:54 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	build_resetenv(char **cmd)
{
	free_tab(g_env);
	init_env(g_env_save);
}
