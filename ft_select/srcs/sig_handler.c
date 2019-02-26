/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rchoquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:11:12 by rchoquet          #+#    #+#             */
/*   Updated: 2018/11/27 17:39:04 by rchoquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	sig_suspend(int sig_num)
{
	struct termios	t_term;
	char			susp[2];

	sig_num = 0;
	if (tcgetattr(0, &t_term) == -1)
		return (ft_putstr_fd("tcgetattr failed (sig_suspend)\n", 2));
	susp[0] = t_term.c_cc[VSUSP];
	susp[1] = 0;
	t_term.c_lflag |= ICANON;
	t_term.c_lflag |= ECHO;
	if (tcsetattr(0, TCSADRAIN, &t_term) == -1)
		return (ft_putstr_fd("tcsetattr failed (sig_suspend)\n", 2));
	signal(SIGTSTP, SIG_DFL);
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	ioctl(0, TIOCSTI, susp);
}

void	sig_winch(int sig_num)
{
	sig_num = 0;
	print_argv(save_begin(NULL), save_end(NULL), *(save_max(NULL)));
	signal(SIGWINCH, sig_winch);
}

void	sig_restart(int sig_num)
{
	char			*name_term;
	struct termios	term;

	sig_num = 0;
	if (!(name_term = getenv("TERM")) && (env_not_found()))
		return ;
	if (tgetent(NULL, name_term) == ERR)
		return (ft_putstr_fd("tgetent failed (sig_restart)\n", 2));
	if (tcgetattr(0, &term) == -1)
		return (ft_putstr_fd("tcgetattr failed (sig_restart)\n", 2));
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (ft_putstr_fd("tcsetattr failed (sig_restart)\n", 2));
	signal(SIGCONT, sig_restart);
	signal(SIGTSTP, sig_suspend);
	sig_winch(0);
}

void	sig_end(int sig_num)
{
	char			*name_term;
	struct termios	term;

	sig_num = 0;
	if (!(name_term = getenv("TERM")) && (env_not_found()))
		return ;
	if (tgetent(NULL, name_term) == ERR)
		return (ft_putstr_fd("tgetent failed (sig_end)\n", 2));
	if (tcgetattr(0, &term) == -1)
		return (ft_putstr_fd("tcgetattr failed (sig_end)\n", 2));
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		return (ft_putstr_fd("tcstattr failed (sig_end)\n", 2));
	ft_putstr_fd(tgetstr("ve", NULL), 0);
	exit(0);
}
