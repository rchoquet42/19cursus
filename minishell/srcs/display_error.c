/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/04 02:51:53 by rchoquet          #+#    #+#             */
/*   Updated: 2018/10/18 22:35:47 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_error(char *str)
{
	char	*tmp;

	tmp = ft_strsub(str, 1, ft_strlen(str) - 1);
	ft_printf_fd(2, "zsh: command not found: %s\n", tmp);
	(tmp != NULL ? free(tmp) : 0);
}

void	display_error_setenv(void)
{
	ft_printf_fd(2, "setenv: Variable name must ");
	ft_printf_fd(2, "contain alphanumeric characters.\n");
}

void	display_error_unsetenv(void)
{
	ft_printf_fd(2, "unsetenv: Too few arguments.\n");
}

void	display_error_dir(char *str)
{
	if (str == NULL)
		ft_printf_fd(2, "cd: no such file or directory\n");
	else
		ft_printf_fd(2, "cd: permission denied\n");
}

void	display_error_env_not_set(char *str)
{
	ft_printf_fd(2, "cd: %s not set\n", str);
}
