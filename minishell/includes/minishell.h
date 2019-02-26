/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 21:57:42 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/27 10:20:52 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define NBUILD 7
# define DEFAULT "\033[0m"
# define HIGHLIGHT "\033[1m"
# define UNDERLINE "\033[4m"
# define BLINK "\033[5m"

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define PURPLE "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

# include "libft.h"
# include "ft_printf.h"
# include <sys/stat.h>
# include <limits.h>
# include <signal.h>

char	**g_env;
char	**g_env_save;
int		g_sub_process;

/*
** init.c
*/
void	init_all(char **envv, void (*f[NBUILD])(char **));
void	init_env(char **env);

/*
** interpreter.c
*/
int		interpreter(char *line, void (*f[NBUILD])(char **));
void	exec_my_build(int i, char **cmd);
int		is_my_build_in(char *cmd);

/*
** exec.c
*/

void	launch_bin(char *file_name, char **argv);

/*
** env.c
*/
char	*get_env(char *name);
int		get_env_id(char *name);
int		get_env_len(void);

/*
** setenv.c
*/
void	ft_setenv(char *name, char *value);
void	realloc_env(int len, int index_del);

/*
** free.c
*/
void	*free_tab(char **tab);
int		free_on_exit(char *line, char **cmd);
char	*free_line(char *str);

/*
** display.c
*/
void	display_error(char *str);
void	display_env(void);
void	display_error_setenv(void);
void	display_error_unsetenv(void);
void	display_error_dir(char *str);
void	display_error_env_not_set(char *str);
void	display_malloc_failed(void);

/*
** build_in
*/
void	build_echo(char **cmd);
void	build_cd(char **cmd);
void	build_env(char **cmd);
void	build_setenv(char **cmd);
void	build_unsetenv(char **cmd);
void	build_resetenv(char **cmd);
void	build_setpcolor(char **cmd);

/*
** split_argv.c
*/
char	**ft_split_argv(char *str);

/*
** utils.c
*/
char	**ft_shift_tab(char **cmd, int i);
char	*get_value(char *key);
char	*set_var_value(char *s1, char *s2);

/*
** signal.c
*/
void	sig_handler(int sig_value);

/*
** bracket_quote.c
*/
char	*wait_quote(char *line);

/*
** display_prompt.c
*/
void	display_prompt(void);

/*
** cd.c
*/

/*
** get_next_line_signal.c
*/
int		get_next_line_signal(const int fd, char **line);

#endif
